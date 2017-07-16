#include "parlex/cpp_generator.hpp"

#include <cmath>
#include <sstream>

#include "parlex/builder.hpp"
#include "parlex/document_representation.hpp"

#include "parlex/details/behavior.hpp"
#include "parlex/details/builtins.hpp"

#include "covariant_invoke.hpp"

namespace parlex {

struct type : details::node {
	type(std::string const & name) : name(name) {}
	std::string name;
};

static std::string const generated_notice = "// This file was generated using Parlex's cpp_generator\n\n";

#pragma region Utility Functions

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
	result << "\n\n";
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

#pragma endregion

#pragma region String Generation

// generate an inline type for the given unit node
static std::string stringize_unit(details::unit const & u, size_t index = std::numeric_limits<size_t>::max()) {
	if (u.tag.empty()) {
		if (index != std::numeric_limits<size_t>::max()) {
			return "std::integral_constant<int, " + std::to_string(index) + ">";
		}
		return "struct {}";
	}
	return "struct " + u.tag + " {}";
}

static std::string generate_struct_members(std::vector<std::pair<std::string, erased<details::node>>> const & flattenedDataMembers) {
	std::stringstream ss;
	for (auto const & flattenedDataMember : flattenedDataMembers) {
		covariant_invoke<void>(*flattenedDataMember.second,
			[&](details::unit const &) { },
			[&](type const & v) {
				ss << v.name + " " + flattenedDataMember.first + ";\n";
			}
		);
	}
	return ss.str();
}

static std::string generate_struct_constructor_parameters(std::vector<std::pair<std::string, erased<details::node>>> const & flattenedDataMembers) {
	std::stringstream ss;
	for (auto const & flattenedDataMember : flattenedDataMembers) {
		covariant_invoke<void>(*flattenedDataMember.second,
			[&](details::unit const &) { },
			[&](type const & v) {
				ss << v.name << " const & " << flattenedDataMember.first;
				if (&flattenedDataMember != &*flattenedDataMembers.rbegin()) {
					ss << ",";
				}
				ss << "\n";
			}
		);
	}
	return ss.str();
}

static std::string generate_struct_constructor_initializers(std::vector<std::pair<std::string, erased<details::node>>> const & flattenedDataMembers) {
	std::stringstream ss;
	for (auto const & flattenedDataMember : flattenedDataMembers) {
		covariant_invoke<void>(*flattenedDataMember.second,
			[&](details::unit const &) {},
			[&](type const & v) {
			ss << flattenedDataMember.first << "(" << flattenedDataMember.first << ")";
			if (&flattenedDataMember != &*flattenedDataMembers.rbegin()) {
				ss << ", ";
			}
		}
		);
	}
	return ss.str();
}

// generate the build(std::vector<parlex::match>::iterator & i, parlex::details::node const & behavior) function {
static std::string generate_struct_builder(details::node const & n) {

}

// generate the builder expression portion of the cpp.inc that constructs the parlex grammar
static std::string generate_grammar_builder_initializer(details::node const & n) {
	auto add_tag = [&]() {
		if (n.tag != "") {
			return enquote(n.tag) + ", ";
		}
		return std::string();
	};

	auto add_children = [&]() {
		std::stringstream ss;
		for (auto const & child : n.children) {
			ss << indent(generate_grammar_builder_initializer(*child));
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
static std::string generate_production_builder_initializer(production const & p) {
	std::stringstream ss;
	ss << "parlex::production(" << enquote(p.id) << ",\n";
	ss << indent(generate_grammar_builder_initializer(*p.behavior), 2);
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

// generate a function that returns the grammar_builder
static std::string generate_grammar_builder(builder const & b) {
	std::stringstream source;
	source << "static parlex::builder const & builder() {\n";
	source << "\tstatic parlex::builder const result(" << enquote(b.root_id) << ", {\n";
	for (auto const & p : b.productions) {
		source << "\t\t" << generate_production_builder_initializer(p);
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

#pragma endregion

#pragma region Node Transformations

static erased<details::node> flatten_node(erased<details::node> const & n, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations);

static details::node::children_t flatten_children(details::node::children_t const & children, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations) {
	details::node::children_t results;
	for (auto const & child : children) {
		auto temp = flatten_node(child, subResults, forwardDeclarations);
		results.push_back(temp);
	}
	return results;
}

// return a type node and any sub results needed to define the referenced type
static erased<details::node> flatten_aggregate(details::aggregate const & aggregate, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations) {
	std::vector<std::string> internalSubResults;
	details::aggregate flattenedAggregate;
	for (auto const & dataMember : aggregate.data_members) {
		flattenedAggregate.add_member(dataMember.first, flatten_node(dataMember.second, internalSubResults, forwardDeclarations));
	}
	auto & flattenedDataMembers = flattenedAggregate.data_members;

	std::stringstream ss;
	ss << "struct";
	if (!aggregate.tag.empty()) {
		ss << " " << aggregate.tag;
	}
	ss << " {\n";
	for (auto const & internalSubResult : internalSubResults) {
		ss << indent(internalSubResult) << "\n\n";
	}
	ss << indent(generate_struct_members(flattenedDataMembers));
	ss << "\n";
	if (!aggregate.tag.empty()) {
		ss << "\t" << aggregate.tag << "(\n";
		ss << indent(generate_struct_constructor_parameters(flattenedDataMembers), 2);
		ss << "\t) : ";
		ss << generate_struct_constructor_initializers(flattenedDataMembers);
		ss << " {}\n";
	}
	ss << "}";

	if (!aggregate.tag.empty()) {
		ss << ";";
		subResults.push_back(ss.str());
		return type(aggregate.tag);
	}
	return type(ss.str());
}

static erased<details::node> flatten_choice_as_enum(details::choice_t const & choice, details::node::children_t const & children, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations) {
	std::set<std::string> enumElements;
	for (auto const & child : children) {
		enumElements.insert(child->tag);
	}
	auto enumDef = generate_enumeration(choice.tag, enumElements);
	if (choice.tag != "") {
		subResults.push_back(enumDef);
		return type(choice.tag);
	}
	return type(enumDef);
}

static erased<details::node> flatten_choice_as_variant(details::node::children_t & children) {
	std::stringstream ss;
	ss << "std::variant<\n";
	for (size_t i = 0; i < children.size(); ++i) {
		auto const & child = children[i];
		auto typeName = covariant_invoke<std::string>(*child,
			[&](details::unit const & v2) {
				return stringize_unit(v2, i);
			},
			[&](type const & v) {
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
	return type(ss.str());
}

static erased<details::node> flatten_choice(details::choice_t const & choice, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations) {
	auto children = flatten_children(choice.children, subResults, forwardDeclarations);
	bool allTaggedUnits = std::all_of(children.begin(), children.end(), [](erased<details::node> const & child) { return child->tag != "" && dynamic_cast<details::unit const *>(&*child) != nullptr; });
	return allTaggedUnits ?
		flatten_choice_as_enum(choice, children, subResults, forwardDeclarations) :
		flatten_choice_as_variant(children);
}

static erased<details::node> flatten_optional(details::optional_t const & optional, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations) {
	auto children = flatten_children(optional.children, subResults, forwardDeclarations);
	auto result = covariant_invoke<std::string>(*children[0],
		[&](details::unit const & v) {
			return "bool";
		},
		[&](type const & v)
		{
			return "std::optional<" + v.name + ">";
		}
	);
	return type(result);
}

static erased<details::node> flatten_repetition(details::repetition_t const & repetition, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations) {
	auto children = flatten_children(repetition.children, subResults, forwardDeclarations);
	auto result = covariant_invoke<std::string>(*children[0],
		[&](details::unit const & v) {
			return "int";
		},
		[&](type const & v)
		{
			return "std::vector<" + v.name + ">";
		}
	);
	return type(result);
}

static erased<details::node> flatten_sequence_as_tuple(details::sequence_t const & sequence, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations) {
	auto children = flatten_children(sequence.children, subResults, forwardDeclarations);
	std::stringstream ss;
	ss << "std::tuple<\n";
	int elementCount = 0;
	for (auto const & child : children) {
		std::string childName = covariant_invoke<std::string>(*child,
			[&](type const & v) {
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
	return type(ss.str());
}

static erased<details::node> flatten_sequence_as_forced_aggregate(details::sequence_t const & sequence, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations) {
	//exclude units from aggregates
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
		forcedAggregate.add_member(fieldName, child);
	}
	return flatten_aggregate(forcedAggregate, subResults, forwardDeclarations);
}

static erased<details::node> flatten_sequence(details::sequence_t const & sequence, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations) {
	if (sequence.tag == "") {
		return flatten_sequence_as_tuple(sequence, subResults, forwardDeclarations);
	}
	//force creation of a new struct
	return flatten_sequence_as_forced_aggregate(sequence, subResults, forwardDeclarations);
}

static erased<details::node> flatten_node(erased<details::node> const & n, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations) {
	erased<details::node> result = covariant_invoke<erased<details::node>>(*n,
		[&](details::unit const & v) { return v; },
		[&](details::reference_t const & v) {
			details::recognizer const * rPtr;
			if (details::builtins().resolve_builtin(v.id, rPtr)) {
				if (dynamic_cast<details::terminal const *>(rPtr) != nullptr) {
					return erased<details::node>(details::unit(v));
				}
				if (rPtr == &details::builtins().c_string) {
					return erased<details::node>(type("std::string"));
				}
				return erased<details::node>(type("std::pair<int, int>"));
			}
			forwardDeclarations.insert(v.id);
			return erased<details::node>(type("erased<" + v.id + ">"));
		},
		[&](type const & v) { return v; },
		[&](details::aggregate const & v) { return flatten_aggregate(v, subResults, forwardDeclarations); },
		[&](details::choice_t const & v) { return flatten_choice(v, subResults, forwardDeclarations); },
		[&](details::optional_t const & v) { return flatten_optional(v, subResults, forwardDeclarations); },
		[&](details::repetition_t const & v) { return flatten_repetition(v, subResults, forwardDeclarations); },
		[&](details::sequence_t const & v) { return flatten_sequence(v, subResults, forwardDeclarations); }
	);
	auto const * asUnit = dynamic_cast<details::unit const *>(&*result);
	auto const * asType = dynamic_cast<type const *>(&*result);
	if (asUnit == nullptr && asType == nullptr) {
		throw std::logic_error("invalid flattened result");
	}
	return result;
}

#pragma endregion

// generate PRODUCTION_ID.hpp
static cpp_generator::output_files generate_production_struct(production const & p) {
	cpp_generator::output_files results;
	auto & headers = results.headers;
	auto & sources = results.sources;

	std::vector<std::string> subResults;
	auto representation = compute_document_representation(p.behavior);
	std::set<std::string> forwardDeclarations;
	auto flattened = flatten_node(representation, subResults, forwardDeclarations);
	std::stringstream ss;
	ss << generated_notice;
	ss << include_guard_start(p.id);
	ss << "#include <optional>\n";
	ss << "#include <variant>\n";
	ss << "#include <vector>\n\n";
	ss << "#include \"erased.hpp\"\n\n";
	covariant_invoke<void>(*flattened,
		[&](type const & value) {
			for (auto const & forwardDeclaration : forwardDeclarations) {
				ss << "struct " << forwardDeclaration << ";\n";
			}
			if (!forwardDeclarations.empty()) {
				ss << "\n";
			}
			for (auto const & subResult : subResults) {
				ss << subResult << "\n\n";
			}
			if (subResults.size() == 0) {
				ss << "typedef " << value.name << " " << p.id << ";";
			}
		},
		[&](details::unit const & value) {
			ss << "struct " << p.id << " {};";
		}
	);
	ss << include_guard_end(p.id);
	headers[p.id + ".hpp"] = ss.str();

	return results;
}

// generate NAME_grammar.hpp.inc and NAME_grammar.cpp.inc
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
