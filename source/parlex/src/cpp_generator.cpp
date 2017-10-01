#include "parlex/cpp_generator.hpp"

#include <cmath>
#include <sstream>

#include "parlex/builder.hpp"
#include "parlex/document_representation.hpp"

#include "parlex/details/behavior.hpp"
#include "parlex/details/builtins.hpp"

#include "covariant_invoke.hpp"
#include <iomanip>
#include "utf.hpp"

namespace parlex {

struct type : details::node {
	type(std::string const & name) : name(name) {}
	std::string name;
};

void cpp_generator::output_files::add(output_files const & other)
{
	for (auto const & header : other.headers) {
		if (headers.emplace(header.first, header.second).second == false) {
			throw std::runtime_error("duplicated file name: " + header.first);
		}
	}
	for (auto const & source : other.sources) {
		if (sources.emplace(source.first, source.second).second == false) {
			throw std::runtime_error("duplicated file name: " + source.first);
		}
	}
}

static std::string const generated_notice = "// This file was generated using Parlex's cpp_generator\n\n";

#pragma region String Generation

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

static std::string string_to_c_name(std::string prefix, std::string const & s) {
	std::string s1 = prefix + s;
	auto test = [](size_t pos, char c)
	{
		return (pos == 0 ? false : c >= '0' && c <= '9') || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '_';
	};

	auto convert = [&test](size_t pos, char c)
	{
		std::string result;
		if (test(pos, c)) {
			result = c;
		} else {
			std::stringstream buffer;
			buffer << std::hex << std::setw(2) << std::setfill('0') << unsigned(*reinterpret_cast<uint8_t *>(&c));
			result = std::string(c == pos ? "_" : "") + "0x" + toupper(buffer.str());
		}
		return result;
	};

	std::string result;
	for (size_t i = 0; i < s1.length(); ++i) {
		result += convert(i, s1[i]);
	}
	return result;
}

static std::string namespaces_start(std::list<std::string> const & namespaces)
{
	std::stringstream result;
	for (auto const & namespace_ : namespaces)
	{
		result << "namespace " << namespace_ << " {\n";
	}
	return result.str();
}

static std::string namespaces_end(std::list<std::string> const & namespaces)
{
	std::stringstream result;
	for (auto const & namespace_ : namespaces)
	{
		result << "} // namespace " << namespace_ << "\n";
	}
	return result.str();
}

static std::string namespaces_access(std::list<std::string> const & namespaces)
{
	std::stringstream result;
	for (auto const & namespace_ : namespaces)
	{
		result << namespace_ << "::";
	}
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

// indent the multi-line string s1 by count tab characters
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
static std::string generate_x_builder_cpp_inc(builder const & b) {
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
static std::string generate_production_member_declarations(builder const & b) {
	std::stringstream result;
	for (auto const & p : b.productions) {
		result << "\t" << "production const & " << p.id << ";\n";
	}
	return result.str();
}

// return a string containing constructor initializers for each production
static std::string generate_production_member_initializers(builder const & b) {
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

static std::string generate_literal_declarations(std::map<std::u32string, std::string> & mapping)
{
	std::stringstream result;
	for (auto const & entry : mapping) {
		result << "struct " << entry.second << "_t {\n";
		result << "\tstatic " << entry.second << "_t const * get();\n";
		result << "}; // " << enquote(to_utf8(entry.first)) << "\n";
		result << "extern " << entry.second << "_t " << entry.second << ";\n\n";
		result << "inline " << entry.second << "_t const * " << entry.second << "_t::get() { return &" << entry.second << "; }\n";
	}
	return result.str();
}

static std::string generate_literal_definitions(std::map<std::u32string, std::string> & mapping)
{
	std::stringstream result;
	for (auto const & entry : mapping) {
		result << entry.second << "_t " << entry.second << ";\n\n";
	}
	return result.str();
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
		ss << "\n";
		ss << "\t" << aggregate.tag << "(\n";
		ss << indent(generate_struct_constructor_parameters(flattenedDataMembers), 2);
		ss << "\t) : ";
		ss << generate_struct_constructor_initializers(flattenedDataMembers);
		ss << " {}\n\n";
		ss << "\tstatic " << aggregate.tag << " build(parlex::details::ast_node const & n);\n\n";
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
				return covariant_invoke<std::string>(v2.original_leaf, [](details::literal_t const & literal){
					return string_to_c_name("literal_", to_utf8(literal.content)) + "_t";
				}, [&](details::node const & n) { return stringize_unit(v2, i); });
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

static std::list<std::u32string> get_literals(builder const & b)
{
	std::list<std::u32string> results;
	std::queue<details::node const *> pending;
	//seed the queue
	for (auto const & production : b.productions)
	{
		pending.push(&*production.behavior);
	}

	while (pending.size() > 0)
	{
		details::node const * n = pending.front();
		pending.pop();
		details::literal_t const * asLiteral = dynamic_cast<details::literal_t const *>(n);
		if (asLiteral != nullptr)
		{
			results.push_back(asLiteral->content);
		}
		for (auto const & child : n->children) {
			pending.push(&*child);
		}
	}

	return results;
}

#pragma endregion

cpp_generator::output_files generate_literals(std::string const & name, std::list<std::string> const & namespaces, builder const & b, std::map<std::u32string, std::string> & mapping)
{
	cpp_generator::output_files results;
	auto & headers = results.headers;
	auto & sources = results.sources;

	auto headerName = "_" + name + "_literals" + ".hpp";

	std::list<std::u32string> literals = get_literals(b);
	for (auto const & literal : literals) {
		mapping[literal] = string_to_c_name("literal_", to_utf8(literal));
	}

	std::stringstream header;
	header << include_guard_start(name + "_literals");
	header << namespaces_start(namespaces);
	header << "\n";
	header << generate_literal_declarations(mapping);
	header << namespaces_end(namespaces);
	header << include_guard_end(name + "_literals");
	headers[headerName] = header.str();

	std::stringstream source;
	source << "#include \"" << headerName << "\"\n\n";
	source << namespaces_start(namespaces);
	source << generate_literal_definitions(mapping);
	source << namespaces_end(namespaces);
	sources["_" + name + "_literals.cpp"] = source.str();
	
	return results;
}

// generate a production's .cpp and .hpp file
static cpp_generator::output_files generate_production_struct(std::string const & grammarName, std::list<std::string> const & namespaces, production const & p) {
	cpp_generator::output_files results;
	auto & headers = results.headers;
	auto & sources = results.sources;

	std::vector<std::string> subResults;
	auto representation = compute_document_representation(p.behavior);
	std::set<std::string> forwardDeclarations;
	auto flattened = flatten_node(representation, subResults, forwardDeclarations);
	std::stringstream header;
	std::stringstream source;
	std::string headerName = p.id + ".hpp";
	header << generated_notice;
	source << generated_notice;
	source << "#include \"" << headerName << "\"\n";

	header << include_guard_start(p.id);
	header << "#include <optional>\n";
	header << "#include <variant>\n";
	header << "#include <vector>\n";
	header << "#include \"erased.hpp\"\n";
	header << "#include \"parlex/details/abstract_syntax_tree.hpp\"\n\n";
	header << "#include \"_" << grammarName << "_literals.hpp\"\n\n";
	header << namespaces_start(namespaces) << "\n";
	covariant_invoke<void>(*flattened,
		[&](type const & value) {
			for (auto const & forwardDeclaration : forwardDeclarations) {
				header << "struct " << forwardDeclaration << ";\n";
				source << "#include \"" << forwardDeclaration << ".hpp\"\n";
			}
			if (!forwardDeclarations.empty()) {
				header << "\n";
			}
			for (auto const & subResult : subResults) {
				header << subResult << "\n\n";
			}
			if (subResults.size() == 0) {
				auto baseName = p.id + "_base";
				header << "typedef " << value.name << " " << baseName << ";\n\n";
				header << "struct " << p.id << ": " << baseName << " {\n";
				header << "\tstatic " << p.id << " build(parlex::details::ast_node const & n);\n";
				header << "\texplicit " << p.id << "(" << baseName << " const & value) : " << baseName << "(value) {}\n";
				header << "};";

				source << "#include \"" << headerName << "\"\n";
				source << "#include \"" << grammarName << "_grammar.hpp\"\n\n";
				source << namespaces_start(namespaces) << "\n";
				source << p.id << " " << p.id << "::build(parlex::details::ast_node const & n) {\n";
				source << "}\n\n";
				source << namespaces_end(namespaces);
			}
		},
		[&](details::unit const & value) {
			header << "struct " << p.id << " {};";
		}
	);
	header << "\n" << namespaces_end(namespaces) << "\n";
	header << include_guard_end(p.id);
	headers[headerName] = header.str();
	sources[p.id + ".cpp"] = source.str();
	return results;
}

//generate text for the grammar's .hpp.inc file
std::string generate_grammar_hpp_inc(std::string const & name, std::list<std::string> const & namespaces, builder const & b)
{
	std::string fullName = name + "_grammar";
	std::stringstream header;
	header << generated_notice;
	header << include_guard_start(fullName);
	header << "#include \"parlex/builder.hpp\"\n\n";
	header << "#include \"parlex/details/grammar.hpp\"\n\n";
	header << namespaces_start(namespaces) << "\n";
	header << "class " << fullName << " : public parlex::details::grammar {\n";
	header << "public:\n";
	header << "static " << fullName << " const & get() {\n";
	header << "\tstatic " << fullName << " value;\n";
	header << "\treturn value;\n";
	header << "}\n\n";
	header << "\t" << fullName << "();\n\n";
	header << generate_production_member_declarations(b);
	header << "};\n\n";
	header << namespaces_end(namespaces) << "\n";
	header << include_guard_end(fullName);
	return header.str();
}

//generate text for the grammar's .cpp.inc file
std::string generate_grammar_cpp_inc(std::string const & name, builder const & b)
{
	std::string fullName = name + "_grammar";
	std::string hppName = "_" + fullName + ".hpp.inc";
	std::string builderCppName = "_" + fullName + "_builder.cpp.inc";

	std::stringstream source;
	source << "#include \"" << hppName << "\"\n";
	source << "#include \"" << builderCppName << "\"\n\n";
	source << fullName << "::" << fullName << "() : grammar(builder()),\n";
	source << generate_production_member_initializers(b);
	source << "\n{}";
	return source.str();
}

cpp_generator::output_files generate_grammar(std::string const & name, std::list<std::string> const & namespaces, builder const & b) {
	cpp_generator::output_files results;
	auto & headers = results.headers;
	auto & sources = results.sources;

	std::string fullName = "_" + name + "_grammar";

	headers[fullName + ".hpp.inc"] = generate_grammar_hpp_inc(name, namespaces, b);
	sources[fullName + "_builder.cpp.inc"] = generate_x_builder_cpp_inc(b);
	sources[fullName + ".cpp.inc"] = generate_grammar_cpp_inc(name, b);

	return results;
}

cpp_generator::output_files cpp_generator::generate(std::string const & name, std::list<std::string> const & namespaces, builder const & b) {
	output_files results;

	for (auto const & production : b.productions) {
		results.add(generate_production_struct(name, namespaces, production));
	}
	std::map<std::u32string, std::string> literalMap;
	results.add(generate_literals(name, namespaces, b, literalMap));
	results.add(generate_grammar(name, namespaces, b));

	return results;
}

} // namespace parlex
