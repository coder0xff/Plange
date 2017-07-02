#include "parlex/cpp_generator.hpp"

#include <cmath>
#include <sstream>

#include "parlex/builder.hpp"
#include "parlex/document_representation.hpp"

#include "parlex/details/behavior.hpp"
#include "parlex/details/builtins.hpp"

#include "covariant_invoke.hpp"

namespace parlex {

static std::string const generated_notice = "// This file was generated using Parlex's cpp_generator\n\n";

static std::string include_guard_name(std::string const & name) {
	return "INCLUDED_" + toupper(name) + "_HPP";
}

static std::string include_guard_start(std::string const & name) {
	std::string guardName = include_guard_name(name);
	std::stringstream result;
	result << "#ifndef " << guardName << "\n";
	result << "#define " << guardName << "\n";
	result << "\n";
	return result.str();
}

static std::string include_guard_end(std::string const & name) {
	std::string guardName = include_guard_name(name);
	std::stringstream result;
	result << "\n";
	result << "#endif //" << guardName << "\n";
	return result.str();

}

// generate a c++ enum class
static std::string generate_enumeration(std::string const & name, std::set<std::string> const & elements) {
	std::stringstream ss;
	ss << "enum class";
	if (!name.empty()) {
		ss << " " << name;
	}
	ss << " {\n";
	for (auto const & element : elements) {
		ss << "\t" << element;
		if (&element != &*elements.rbegin()) {
			ss << ",";
		}
		ss << "\n";
	}
	ss << "}";
	return ss.str();
}

// merge the files given in from into to
static void add_files(cpp_generator::output_files & to, cpp_generator::output_files const & from) {
	for (auto const & header : from.headers) {
		if (to.headers.emplace(header.first, header.second).second == false) {
			throw std::runtime_error("duplicated file name: " + header.first);
		}
	}
	for (auto const & source : from.sources) {
		if (to.sources.emplace(source.first, source.second).second == false) {
			throw std::runtime_error("duplicated file name: " + source.first);
		}
	}
}

// indent the multi-line string s by count tab characters
static std::string indent(std::string const & s, int count = 1) {
	std::stringstream in(s);
	std::stringstream result;
	std::string indentStr(count, '\t');
	std::string line;
	while (getline(in, line)) {
		result << indentStr << line;
		if (in.eof()) { //only add a trailing newline on the last line if there was one in the input
			if (*s.rbegin() == '\n') {
				result << "\n";
			}
		} else {
			result << "\n";
		}
	}
	return result.str();
}

// generate an inline type for the given unit node
static std::string stringize_unit(details::unit const & u, size_t index = std::numeric_limits<size_t>::max()) {
	if (u.tag.empty()) {
		if (index != std::numeric_limits<size_t>::max()) {
			return "std::std::integral_constant<int, " + std::to_string(index) + ">";
		}
		return "struct {}";
	}
	return "struct " + u.tag + " {}";
}

// generate a builder expression portion of the cpp.inc that constructs the parlex grammar
static std::string node_to_cpp(details::node const & n) {
	auto add_tag = [&]() {
		if (n.tag != "") {
			return enquote(n.tag) + ", ";
		}
		return std::string();
	};

	auto add_children = [&]() {
		std::stringstream ss;
		for (auto const & child : n.children) {
			ss << indent(node_to_cpp(*child));
			if (&*child != &**n.children.rbegin()) {
				ss << ",";
			}
			ss << '\n';
		}
		return ss.str();
	};

#define DO_AS(name)	[&](details::name##_t const & v) { return "parlex::" #name "(" + add_tag() + "{\n" + add_children() + "})"; }

	return covariant_invoke<std::string>(n,
	                                     [&](details::literal_t const & v) {
	                                     return "parlex::literal(" + add_tag() + enquote(v.id) + ")";
                                     },
	                                     [&](details::reference_t const & v) {
	                                     return "parlex::reference(" + add_tag() + enquote(v.id) + ")";
                                     },
	                                     DO_AS(choice),
	                                     DO_AS(optional),
	                                     DO_AS(repetition),
	                                     DO_AS(sequence)
	);

#undef DO_AS

}

// generate a portion of the cpp.inc that construct the parlex grammar
static std::string production_to_cpp(production const & p) {
	std::stringstream ss;
	ss << "parlex::production(" << enquote(p.id) << ",\n";
	ss << indent(node_to_cpp(*p.behavior), 2);
	bool needsPrecendences = p.precedences.size() > 0;
	bool needsFilter = p.filter != filter_function() || needsPrecendences;
	bool needsAssociativity = p.assoc != associativity::none || needsFilter;
	if (needsAssociativity) {
		ss << ",\n\t\tparlex::associativity::";
		switch (p.assoc) {
			case associativity::any:
				ss << "any";
				break;
			case associativity::left:
				ss << "left";
				break;
			case associativity::none:
				ss << "none";
				break;
			case associativity::right:
				ss << "right";
				break;
		}
	}
	if (needsFilter) {
		ss << ", ";
		if (p.filter == details::builtins().longest) {
			ss << "parlex::details::builtins().longest";
		} else if (!p.filter) {
			ss << "parlex::filter_function()";
		} else {
			throw;
		}
	}
	if (needsPrecendences) {
		ss << ", {";
		for (auto const & precedence : p.precedences) {
			ss << enquote(precedence) << ", ";
		}
		ss << "}";
	}
	ss << ")";
	return ss.str();
}

static erased<details::node> flatten_node(erased<details::node> const & n, std::vector<std::string> & subResults);

static details::node::children_t flatten_children(details::node::children_t const & children, std::vector<std::string> & subResults) {
	details::node::children_t results;
	for (auto const & child : children) {
		auto temp = flatten_node(child, subResults);
		results.push_back(temp);
	}
	return results;
}

// return a type node and any sub results needed to define the referenced type
static erased<details::node> flatten_aggregate(details::aggregate const & aggregate, std::vector<std::string> & subResults) {
	std::vector<std::string> internalSubResults;
	std::map<std::string /* data member name */, erased<details::node>> flattenedDataMembers;
	for (auto const & dataMember : aggregate.data_members) {
		flattenedDataMembers.emplace(std::piecewise_construct, forward_as_tuple(dataMember.first), std::forward_as_tuple(flatten_node(dataMember.second, internalSubResults)));
	}
	
	std::stringstream ss;
	ss << "struct";
	if (!aggregate.tag.empty()) {
		ss << " " << aggregate.tag;
	}
	ss << " {\n";
	for (auto const & internalSubResult : internalSubResults) {
		ss << indent(internalSubResult) << "\n\n";
	}
	for (auto const & flattenedDataMember : flattenedDataMembers) {
		ss << indent(covariant_invoke<std::string>(*flattenedDataMember.second,
			[&](details::unit const &) { return ""; },
			[&](details::type const & v) {
				return v.name + " " + flattenedDataMember.first + ";\n";
			}
		));
	}
	ss << "}";

	if (!aggregate.tag.empty()) {
		ss << ";";
		subResults.push_back(ss.str());
		return details::type(aggregate.tag);
	}
	return details::type(ss.str());
}

static std::string flattened_choice_enum(details::choice_t const & choice, details::node::children_t const & children, std::vector<std::string> & subResults) {
	std::set<std::string> enumElements;
	for (auto const & child : children) {
		enumElements.insert(child->tag);
	}
	auto enumDef = generate_enumeration(choice.tag, enumElements);
	if (choice.tag != "") {
		subResults.push_back(enumDef);
		return choice.tag;
	}
	return enumDef;
}

static std::string flattened_choice_variant(details::node::children_t & children) {
	std::stringstream ss;
	ss << "std::variant<\n";
	for (size_t i = 0; i < children.size(); ++i) {
		auto const & child = children[i];
		auto typeName = covariant_invoke<std::string>(*child,
			[&](details::unit const & v2) {
				return stringize_unit(v2, i);
			},
			[&](details::type const & v) {
				return v.name;
			}
		);
		ss << indent(typeName);
		if (i < children.size() - 1) {
			ss << ",";
		}
		ss << "\n";
	}
	ss << ">";
	return ss.str();
}

static erased<details::node> flatten_choice(details::choice_t const & choice, std::vector<std::string> & subResults) {
	auto children = flatten_children(choice.children, subResults);
	bool allTaggedUnits = std::all_of(children.begin(), children.end(), [](erased<details::node> const & child) { return child->tag != "" && dynamic_cast<details::unit const *>(&*child) != nullptr; });
	std::string result = allTaggedUnits ?
		flattened_choice_enum(choice, children, subResults) :
		flattened_choice_variant(children);
	return details::type(result);
}

static erased<details::node> flatten_optional(details::optional_t const & optional, std::vector<std::string> & subResults) {
	auto children = flatten_children(optional.children, subResults);
	auto result = covariant_invoke<std::string>(*children[0],
		[&](details::unit const & v) {
			return "bool";
		},
		[&](details::type const & v)
		{
			return "std::optional<" + v.name + ">";
		}
	);
	return details::type(result);
}

static erased<details::node> flatten_repetition(details::repetition_t const & repetition, std::vector<std::string> & subResults) {
	auto children = flatten_children(repetition.children, subResults);
	auto result = covariant_invoke<std::string>(*children[0],
		[&](details::unit const & v) {
			return "int";
		},
		[&](details::type const & v)
		{
			return "std::vector<" + v.name + ">";
		}
	);
	return details::type(result);
}

static erased<details::node> flattened_sequence_tuple(details::sequence_t const & sequence, std::vector<std::string> & subResults) {
	auto children = flatten_children(sequence.children, subResults);
	std::stringstream ss;
	ss << "std::tuple<\n";
	int elementCount = 0;
	for (auto const & child : children) {
		std::string childName = covariant_invoke<std::string>(*child,
			[&](details::type const & v) {
				return v.name;
			},
			[&](details::unit const & v) {
				return "";
			}
		);
		if (!childName.empty()) {
			if (elementCount > 0) {
				ss << ",\n";
			}
			ss << indent(childName);
			++elementCount;
		}
	}
	if (elementCount == 0) {
		return details::unit(sequence);
	}
	ss << "\n>";
	return details::type(ss.str());
}

static erased<details::node> flattened_sequence_forced_aggregate(details::sequence_t const & sequence, std::vector<std::string> & subResults) {
	details::node::children_t children;
	for (auto const & child : sequence.children) {
		if (dynamic_cast<details::unit const *>(&*child) == nullptr) {
			children.push_back(child);
		}
	}

	details::aggregate forcedAggregate;
	forcedAggregate.tag = sequence.tag;
	int untaggedCount = 1;
	for (auto const & child : children) {
		if (child->tag.empty()) {
			++untaggedCount;
		}
	}
	int numberLength = int(ceil(log10(untaggedCount)));
	untaggedCount = 1;
	for (auto const & child : children) {
		std::string fieldName;
		if (child->tag.empty()) {
			std::string number = std::to_string(untaggedCount);
			fieldName = "field_" + std::string(numberLength - number.length(), '0') + number;
			++untaggedCount;
		} else {
			fieldName = child->tag;
		}
		if (!forcedAggregate.data_members.emplace(std::piecewise_construct, forward_as_tuple(fieldName), std::forward_as_tuple(child)).second) {
			throw std::runtime_error("duplicate field name");
		}
	}
	return flatten_aggregate(forcedAggregate, subResults);
}

static erased<details::node> flatten_sequence(details::sequence_t const & sequence, std::vector<std::string> & subResults) {
	if (sequence.tag == "") {
		return flattened_sequence_tuple(sequence, subResults);
	}
	//force creation of a new struct
	return flattened_sequence_forced_aggregate(sequence, subResults);
}

static erased<details::node> flatten_node(erased<details::node> const & n, std::vector<std::string> & subResults) {
	erased<details::node> result = covariant_invoke<erased<details::node>>(*n,
		[&](details::unit const & v) { return v; },
		[&](details::type const & v) { return v; },
		[&](details::aggregate const & v) { return flatten_aggregate(v, subResults); },
		[&](details::choice_t const & v) { return flatten_choice(v, subResults); },
		[&](details::optional_t const & v) { return flatten_optional(v, subResults); },
		[&](details::repetition_t const & v) { return flatten_repetition(v, subResults); },
		[&](details::sequence_t const & v) { return flatten_sequence(v, subResults); }
	);
	auto const * asUnit = dynamic_cast<details::unit const *>(&*result);
	auto const * asType = dynamic_cast<details::type const *>(&*result);
	if (asUnit == nullptr && asType == nullptr) {
		throw std::logic_error("invalid flattened result");
	}
	return result;
}

// generate a function that returns the grammar_builder
static std::string generate_grammar_builder(builder const & b) {
	std::stringstream source;
	source << "static parlex::builder const & builder() {\n";
	source << "\tstatic parlex::builder const result(" << enquote(b.root_id) << ", {\n";
	for (auto const & p : b.productions) {
		source << "\t\t" << production_to_cpp(p);
		source << ",\n";
	}
	source << "\t});\n";
	source << "\treturn result;\n";
	source << "}\n";
	return source.str();
}

// return a string containing data-member declarations for each production
static std::string generate_grammar_members(builder const & b) {
	std::stringstream ss;
	for (auto const & p : b.productions) {
		ss << "\t" << "production const & " << p.id << ";\n";
	}
	return ss.str();
}

// return a string containing constructor initializers for each production
static std::string generate_grammar_initializer(builder const & b) {
	std::stringstream ss;
	bool isFirst = true;
	for (auto const & p : b.productions) {
		if (isFirst) {
			isFirst = false;
		} else {
			ss << ",\n";
		}
		ss << "\t\t\t" << p.id << "(this->get_production(" + enquote(p.id) + "))";
	}
	return ss.str();
}

// generate the 
cpp_generator::output_files generate_grammar(std::string const & name, builder const & b) {
	std::string fullName = name + "_grammar";
	std::string hppName = fullName + ".hpp.inc";
	std::string cppName = fullName + ".cpp.inc";

	cpp_generator::output_files results;
	auto & headers = results.headers;
	auto & sources = results.sources;

	std::stringstream header;
	header << generated_notice;
	header << include_guard_start(fullName);
	header << "class " << fullName << " : public parlex::details::grammar {\n";
	header << "public:\n";
	header << "\t" << fullName << "();\n\n";
	header << generate_grammar_members(b);
	header << "};\n";
	header << include_guard_end(fullName);
	headers[hppName] = header.str();

	std::string builderHeaderName = fullName + "_builder.cpp.inc";
	sources[builderHeaderName] = generate_grammar_builder(b);

	std::stringstream source;
	source << "#include \"" << hppName << "\"\n";
	source << "#include \"" << builderHeaderName << "\"\n\n";
	source << fullName << "::" << fullName << "() : grammar(builder()),\n";
	source << generate_grammar_initializer(b);
	source << "\n{}";
	sources[cppName] = source.str();

	return results;
}

static cpp_generator::output_files generate_production_struct(production const & p) {
	cpp_generator::output_files results;
	auto & headers = results.headers;
	auto & sources = results.sources;

	std::vector<std::string> subResults;
	auto representation = compute_document_representation(p.behavior);
	auto flattened = flatten_node(representation, subResults);
	headers[p.id + ".hpp"] = covariant_invoke<std::string>(*flattened,
		[&](details::type const & value) {
			std::string includeGuardName = include_guard_name(p.id);
			std::stringstream ss;
			ss << generated_notice;
			ss << "#ifndef " << includeGuardName << "\n";
			ss << "#define " << includeGuardName << "\n";
			for (auto const & subResult : subResults) {
				ss << subResult << "\n\n";
			}
			if (subResults.size() == 0) {
				ss << "typedef " << value.name << " " << p.id << ";";
			}
			ss << "#endif //" << includeGuardName;
			return ss.str();
		}
	);

	return results;
}

cpp_generator::output_files cpp_generator::generate(std::string const & name, builder const & b) {
	output_files results;
	auto & headers = results.headers;
	auto & sources = results.sources;

	for (auto const & production : b.productions) {
		add_files(results, generate_production_struct(production));
	}
	add_files(results, generate_grammar(name, b));

	return results;
}

} // namespace parlex
