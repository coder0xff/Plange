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

static std::string grammar_header_name(std::string const & grammarName) {
	return grammarName + "_grammar.hpp";
}

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
static std::string generate_enumeration(bool isProduction, std::string const & grammarName, std::string const & name, std::set<std::string> const & elements) {
	throw_assert(!name.empty());
	std::stringstream ss;
	ss << "struct " << name << " {\n";
	ss << "\tenum type {\n";
	for (auto const & element : elements) {
		ss << "\t\t" << element;
		if (&element != &*elements.rbegin()) {
			ss << ",";
		}
		ss << "\n";
	}
	ss << "\t} value;\n\n";
	ss << "\tstatic " << name << " build(std::u32string const & document, ";
	if (!isProduction) {
		ss << "parlex::details::behavior::node const & b, ";
	}
	ss << "parlex::details::ast_node const & n) {\n";
	ss << "\t\tstatic ::std::unordered_map<parlex::details::recognizer const *, type> const table {\n";
	for (auto const & element : elements) {
		if (element.substr(0, 8) != "literal_") {
			debugger();
		}
		ss << "\t\t\t{ &" << grammarName << "_grammar::get().get_literal(\"" << element << "\"), " << element << " },\n";
	}
	ss << "\t\t};\n";
	ss << "\t\treturn " << name << "{ table.find(&n.r)->second };\n";
	ss << "\t}\n";
	ss << "};\n";
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

static std::string generate_struct_members(details::aggregate::data_members_t const & flattenedDataMembers) {
	std::stringstream ss;
	for (auto const & flattenedDataMember : flattenedDataMembers) {
		if (flattenedDataMember.first == "") {
			continue;
		}
		covariant_invoke<void>(*flattenedDataMember.second,
			[&](details::literal_t const &) {},
			[&](type const & t) {				
				ss << t.name + " " + flattenedDataMember.first + ";\n\n";
			}
		);
	}
	return ss.str();
}

static std::string generate_struct_constructor_parameters(details::aggregate::data_members_t const & flattenedDataMembers) {
	std::stringstream ss;
	auto needsComma = false;
	for (auto const & flattenedDataMember : flattenedDataMembers) {
		if (flattenedDataMember.first == "") {
			continue;
		}
		covariant_invoke<void>(*flattenedDataMember.second,
			[&](details::literal_t const &) {},
			[&](type const & t) {
				if (needsComma) {
					ss << ", ";
				}
				else {
					needsComma = true;
				}
				ss << t.name << " && " << flattenedDataMember.first;
			}
		);
	}
	return ss.str();
}

static std::string generate_struct_constructor_initializers(details::aggregate::data_members_t const & flattenedDataMembers) {
	std::stringstream ss;
	auto needsComma = false;
	for (auto const & flattenedDataMember : flattenedDataMembers) {
		covariant_invoke<void>(*flattenedDataMember.second,
			[&](details::literal_t const &) {},
			[&](type const & t) {
				if (needsComma) {
					ss << ", ";
				}
				else {
					needsComma = true;
				}
				ss << flattenedDataMember.first << "(std::move(" << flattenedDataMember.first << "))";
			}
		);
	}
	return ss.str();
}

static std::string generate_struct_builder_children(details::aggregate::data_members_t const & flattenedDataMembers) {
	std::stringstream ss;
	int childCounter = 0;
	int varCounter = 0;
	for (auto const & flattenedDataMember : flattenedDataMembers) {
		covariant_invoke<void>(*flattenedDataMember.second,
			[&](details::literal_t const & l) {
				ss << "assert(w.pos != w.end); ++w.pos; //" << l.id << " \n";
			},
			[&](type const & t) {
				ss << "auto v_" << varCounter++ << " = parlex::details::document::element<" << t.name << ">::build(document, *children[" << childCounter << "], w);\n";
			}
		);
		childCounter++;
	}
	return ss.str();
}

static std::string generate_struct_build_moves(details::aggregate::data_members_t const & flattenedDataMembers) {
	std::stringstream ss;
	int counter = 0;
	auto needsComma = false;
	for (auto const & flattenedDataMember : flattenedDataMembers) {
		covariant_invoke<void>(*flattenedDataMember.second,
			[&](details::literal_t const &) {},
			[&](type const & t) {
				if (needsComma) {
					ss << ", ";					
				}
				else {
					needsComma = true;
				}
				ss << "std::move(v_" << counter++ << ")";
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
		result << "// " << enquote(to_utf8(entry.first)) << "\n";
		result << "struct " << entry.second << "_t {\n";
		result << "\tstatic " << entry.second << "_t  build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) { return " << entry.second << "_t(); }\n";
		result << "};\n";
	}
	return result.str();
}

// static std::string generate_literal_definitions(std::map<std::u32string, std::string> & mapping)
// {
// 	std::stringstream result;
// 	for (auto const & entry : mapping) {
// 		result << entry.second << "_t " << entry.second << ";\n\n";
// 	}
// 	return result.str();
// }

#pragma endregion

#pragma region Node Transformations

static erased<details::node> flatten_node(bool isProduction, std::string const & grammarName, erased<details::node> & n, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations, std::list<std::string> const & scopes, std::vector<std::string> & builderDefinitions, bool & fullyDefined);

static details::node::children_t flatten_children(std::string const & grammarName, std::string const & elementNameHint, details::node::children_t & children, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations, std::list<std::string> const & scopes, std::vector<std::string> & builderDefinitions) {
	details::node::children_t results;
	int counter = 0;
	for (auto & child : children) {
		if (child->tag == "") {
			child->tag = elementNameHint + "_" + std::to_string(counter++ + 1) + "_t";
		}
		bool dontCareChildWasFullyDefined;
		auto temp = flatten_node(false, grammarName, child, subResults, forwardDeclarations, scopes, builderDefinitions, dontCareChildWasFullyDefined);
		results.push_back(temp);
	}
	return results;
}

static std::string generate_struct_build_parameters(bool isProduction) {
	std::stringstream signatureParams;
	signatureParams << "std::u32string const & document, ";
	if (isProduction) {
		signatureParams << "parlex::details::ast_node const & n";
	} else {
		signatureParams << "parlex::details::behavior::node const & b, parlex::details::document::walk & w";
	}
	return signatureParams.str();
}

static std::string generate_struct_declaration(bool isProduction, std::string const & name, std::vector<std::string> const & internalSubResults, details::aggregate::data_members_t const & flattenedDataMembers) {
	std::stringstream declaration;

	declaration << "struct " << name << " {\n";
	for (auto const & internalSubResult : internalSubResults) {
		declaration << indent(internalSubResult) << "\n\n";
	}
	declaration << indent(generate_struct_members(flattenedDataMembers));
	declaration << "\n\n";
	declaration << "\texplicit " << name << "(\n";
	declaration << indent(generate_struct_constructor_parameters(flattenedDataMembers), 2);
	declaration << ")";
	if (flattenedDataMembers.size() > 0) {
		declaration << " : ";
		declaration << generate_struct_constructor_initializers(flattenedDataMembers);
	}
	declaration << " {}\n\n";
	declaration << "\t" << name << "(" << name << " const & other) = default;\n";
	declaration << "\t" << name << "(" << name << " && move) = default;\n\n";
	declaration << "\tstatic " << name << " build(";
	declaration << generate_struct_build_parameters(isProduction);
	declaration << ");\n\n";
	declaration << "}";
	declaration << ";";
	return declaration.str();
}

// return a type node and any sub results needed to define the referenced type
static erased<details::node> flatten_aggregate(bool isProduction, std::string const & grammarName, details::aggregate const & aggregate, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations, std::list<std::string> const & scopes, std::vector<std::string> & builderDefinitions) {
	throw_assert(!aggregate.tag.empty());
	std::vector<std::string> internalSubResults;
	details::aggregate flattenedAggregate;
	for (auto dataMember : aggregate.data_members) {
		// assign a name for the type of this member if it does not have one
		if (dataMember.second->tag == "") {
			dataMember.second->tag = dataMember.first + "_t";
		}
		bool memberWasFullyDefined;
		auto flattenedMember = flatten_node(false, grammarName, dataMember.second, internalSubResults, forwardDeclarations, scopes, builderDefinitions, memberWasFullyDefined);
		flattenedAggregate.add_member(dataMember.first, flattenedMember);
	}
	auto & flattenedDataMembers = flattenedAggregate.data_members;
	auto declaration = generate_struct_declaration(isProduction, aggregate.tag, internalSubResults, flattenedDataMembers);

	std::stringstream builderDefinition;
	std::string fullyQualifiedName = namespaces_access(scopes);
	fullyQualifiedName = fullyQualifiedName.substr(0, fullyQualifiedName.size() - 2);
	builderDefinition << fullyQualifiedName << " " << fullyQualifiedName << "::build(" << generate_struct_build_parameters(isProduction) << ") {\n";
	if (isProduction) {
		builderDefinition << "\tstatic auto const & b = " << grammarName << "_grammar::get()." << aggregate.tag << ".get_behavior();\n";
		builderDefinition << "\tparlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };\n";
	}
	builderDefinition << "\tauto const & children = b.get_children();\n";
	builderDefinition << indent(generate_struct_builder_children(flattenedDataMembers));
	builderDefinition << "\treturn " << aggregate.tag << "(";
	builderDefinition << generate_struct_build_moves(flattenedDataMembers);
	builderDefinition << ");\n";
	builderDefinition << "}\n";

	builderDefinitions.push_back(builderDefinition.str());

	subResults.push_back(declaration);
	return type(aggregate.tag);
}

static erased<details::node> flatten_choice_as_enum(bool isProduction, std::string const & grammarName, details::choice_t const & choice, details::node::children_t const & children, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations, std::vector<std::string> & builderDefinitions) {
	std::set<std::string> enumElements;
	for (auto const & child : children) {
		details::unit const * asUnit = dynamic_cast<details::unit const *>(&*child);
		if (asUnit->original_leaf.tag != "") {
			enumElements.insert(asUnit->original_leaf.tag);
		} else {
			enumElements.insert(asUnit->tag);
		}
	}
	auto enumDef = generate_enumeration(isProduction, grammarName, choice.tag, enumElements);
	if (choice.tag != "") {
		subResults.push_back(enumDef);
		return type(choice.tag);
	}
	subResults.push_back(enumDef);
	return type(choice.tag);
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
			[&](details::literal_t const & l) {
				return string_to_c_name("literal_", l.id) + "_t";
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

static erased<details::node> flatten_choice(bool isProduction, std::string const & grammarName, details::choice_t & choice, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations, std::list<std::string> const & scopes, std::vector<std::string> & builderDefinitions, bool & fullyDefined) {
	throw_assert(!choice.tag.empty());
	// If all flattened child nodes are tagged units then we want to make an enum, otherwise a variant.
	// Getting this information requires calling flatten_children, which will modify subResults, forwardDeclarations, and builderDefinitions
	// However, the scopes list is dependent on whether it's enum or variant, so we need to isolate the first invocation
	bool allTaggedUnits;
	{
		std::vector<std::string> dontCareSubResults;
		std::set<std::string> dontCareForwardDeclarations;
		std::vector<std::string> dontCareBuilderDefinitions;
		auto children = flatten_children(grammarName, choice.tag, choice.children, dontCareSubResults, dontCareForwardDeclarations, scopes, dontCareBuilderDefinitions);
		allTaggedUnits = std::all_of(children.begin(), children.end(), [](erased<details::node> const & child) { return child->tag != "" && dynamic_cast<details::unit const *>(&*child) != nullptr; });
	}
	if (allTaggedUnits) {
		auto children = flatten_children(grammarName, choice.tag, choice.children, subResults, forwardDeclarations, scopes, builderDefinitions);
		fullyDefined = true;
		return flatten_choice_as_enum(isProduction, grammarName, choice, children, subResults, forwardDeclarations, builderDefinitions);
	} else {
		std::list<std::string> newScopes(scopes);
		newScopes.pop_back();
		auto children = flatten_children(grammarName, choice.tag, choice.children, subResults, forwardDeclarations, newScopes, builderDefinitions);
		fullyDefined = false;
		return flatten_choice_as_variant(children);
	}
}

static erased<details::node> flatten_optional(std::string const & grammarName, details::optional_t & optional, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations, std::list<std::string> const & scopes, std::vector<std::string> & builderDefinitions) {
	throw_assert(!optional.tag.empty());
	std::list<std::string> newScopes(scopes);
	newScopes.pop_back(); // the child will be lifted out, so skip this scope
	auto children = flatten_children(grammarName, optional.tag, optional.children, subResults, forwardDeclarations, newScopes, builderDefinitions);
	auto result = covariant_invoke<std::string>(*children[0],
		[&](details::unit const & v) {
			return "bool";
		},
		[&](details::literal_t const & v) {
			return "bool";
		},
		[&](type const & v)
		{
			return "std::optional<" + v.name + ">";
		}
	);
	return type(result);
}

static erased<details::node> flatten_repetition(std::string const & grammarName, details::repetition_t & repetition, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations, std::list<std::string> const & scopes, std::vector<std::string> & builderDefinitions) {
	throw_assert(!repetition.tag.empty());
	std::list<std::string> newScopes(scopes);
	newScopes.pop_back(); // the child will be lifted out, so skip this scope
	auto children = flatten_children(grammarName, repetition.tag, repetition.children, subResults, forwardDeclarations, newScopes, builderDefinitions);
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

static erased<details::node> flatten_sequence_as_tuple(std::string const & grammarName, details::sequence_t & sequence, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations, std::list<std::string> const & scopes, std::vector<std::string> & builderDefinitions) {
	throw_assert(!sequence.tag.empty());
	auto children = flatten_children(grammarName, sequence.tag, sequence.children, subResults, forwardDeclarations, scopes, builderDefinitions);
	std::stringstream ss;
	ss << "std::tuple<\n";
	int elementCount = 0;
	for (auto const & child : children) {
		covariant_invoke<void>(*child,
			[&](type const & v) {
				ss << "\t" << v.name;
				if (elementCount > 0) {
					ss << ",\n";
				}
				elementCount++;
			},
			[&](details::unit const & v) {},
			[&](details::literal_t const & l) {}
		);
	}
	if (elementCount == 0) {
		return details::unit(sequence);
	}
	ss << "\n>";
	return type(ss.str());
}


static details::node::children_t flatten_children(details::node::children_t children)
{
	std::vector<std::string> dontCareSubResults;
	std::set<std::string> dontCareForwardDeclarations;
	std::vector<std::string> dontCareBuilderDefinitions;
	return flatten_children("", "", children, dontCareSubResults, dontCareForwardDeclarations, std::list<std::string>(), dontCareBuilderDefinitions);
}

static erased<details::node> flatten_sequence_as_forced_aggregate(bool isProduction, std::string const & grammarName, details::sequence_t & sequence, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations, std::list<std::string> const & scopes, std::vector<std::string> & builderDefinitions) {
	int untaggedCount = 0;
	for (auto const & child : flatten_children(sequence.children)) {
		auto asUnit = dynamic_cast<details::unit const *>(&*child);
		auto asLiteral = dynamic_cast<details::literal_t const *>(&*child);
		if (asUnit == nullptr && asLiteral == nullptr && child->tag.empty()) {
			++untaggedCount;
		}
	}

	details::aggregate forcedAggregate;
	forcedAggregate.tag = sequence.tag;
	int numberLength = int(ceil(log10(untaggedCount + 2)));
	untaggedCount = 0;
	int childIndex = 0;
	for (auto child : sequence.children) {
		std::string fieldName;
		auto asUnit = dynamic_cast<details::unit const *>(&*child);
		auto asLiteral = dynamic_cast<details::literal_t const *>(&*child);
		if (asUnit == nullptr && asLiteral == nullptr) {
			if (child->tag.empty()) {
				std::string number = std::to_string(untaggedCount + 1);
				fieldName = "field_" + std::string(numberLength - number.length(), '0') + number;
				++untaggedCount;
			}
			else {
				fieldName = child->tag;
				child->tag = child->tag + "_t";
			}
		} else {
			fieldName = "dontCare" + std::to_string(childIndex);
		}
		forcedAggregate.add_member(fieldName, child);
		++childIndex;
	}
	return flatten_aggregate(isProduction, grammarName, forcedAggregate, subResults, forwardDeclarations, scopes, builderDefinitions);
}

static erased<details::node> flatten_sequence(bool isProduction, std::string const & grammarName, details::sequence_t & sequence, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations, std::list<std::string> const & scopes, std::vector<std::string> & builderDefinitions, bool & fullyDefined) {
	if (sequence.tag == "") {
		fullyDefined = false;
		return flatten_sequence_as_tuple(grammarName, sequence, subResults, forwardDeclarations, scopes, builderDefinitions);
	}
	//force creation of a new struct
	fullyDefined = true;
	return flatten_sequence_as_forced_aggregate(isProduction, grammarName, sequence, subResults, forwardDeclarations, scopes, builderDefinitions);
}

static erased<details::node> literal_to_type(details::literal_t const & l) {
	return type(string_to_c_name("literal_", l.id) + "_t");
}

static erased<details::node> flatten_node(bool isProduction, std::string const & grammarName, erased<details::node> & n, std::vector<std::string> & subResults, std::set<std::string> & forwardDeclarations, std::list<std::string> const & scopes, std::vector<std::string> & builderDefinitions, bool & fullyDefined) {
	fullyDefined = false;
	std::list<std::string> newScopes(scopes);
	newScopes.push_back(n->tag);
	erased<details::node> result = covariant_invoke<erased<details::node>>(*n,
		[&](details::literal_t & l) { return l; },
		[&](details::unit & v) { return v; },
		[&](details::reference_t & v) {
			details::recognizer const * rPtr;
			if (details::builtins().resolve_builtin(v.id, rPtr)) {
				if (dynamic_cast<details::terminal const *>(rPtr) != nullptr) {
					fullyDefined = false;
					return erased<details::node>(type("parlex::details::document::built_in_terminal<parlex::details::" + v.id + "_t>"));
				}
				if (rPtr == &details::builtins().c_string) {
					return erased<details::node>(type("std::string"));
				}
				return erased<details::node>(type("std::pair<int, int>"));
			}
			forwardDeclarations.insert(v.id);
			fullyDefined = false;
			return erased<details::node>(type("erased<" + v.id + ">"));
		},
		[&](type & v) { return v; },
		[&](details::aggregate & v) { return flatten_aggregate(isProduction, grammarName, v, subResults, forwardDeclarations, newScopes, builderDefinitions); },
		[&](details::choice_t & v) { return flatten_choice(isProduction, grammarName, v, subResults, forwardDeclarations, newScopes, builderDefinitions, fullyDefined); },
		[&](details::optional_t & v) { return flatten_optional(grammarName, v, subResults, forwardDeclarations, newScopes, builderDefinitions);	},
		[&](details::repetition_t & v) { return flatten_repetition(grammarName, v, subResults, forwardDeclarations, newScopes, builderDefinitions); },
		[&](details::sequence_t & v) { return flatten_sequence(isProduction, grammarName, v, subResults, forwardDeclarations, newScopes, builderDefinitions, fullyDefined); }
	);
	auto const * asUnit = dynamic_cast<details::unit const *>(&*result);
	auto const * asType = dynamic_cast<type const *>(&*result);
	auto const * asLiteral = dynamic_cast<details::literal_t const *>(&*result);
	if (asUnit == nullptr && asType == nullptr && asLiteral == nullptr) {
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

	auto headerName = "_" + name + "_literals" + ".hpp";

	std::list<std::u32string> literals = get_literals(b);
	for (auto const & literal : literals) {
		mapping[literal] = string_to_c_name("literal_", to_utf8(literal));
	}

	std::stringstream header;
	header << include_guard_start(name + "_literals");
	header << "#include \"parlex/details/document.hpp\"\n\n";
	header << namespaces_start(namespaces);
	header << "\n";
	header << generate_literal_declarations(mapping);
	header << namespaces_end(namespaces);
	header << include_guard_end(name + "_literals");
	headers[headerName] = header.str();

// 	std::stringstream source;
// 	source << "#include \"" << headerName << "\"\n\n";
// 	source << namespaces_start(namespaces);
// 	//source << generate_literal_definitions(mapping);
// 	source << namespaces_end(namespaces);
// 	sources["_" + name + "_literals.cpp"] = source.str();
	
	return results;
}

void tag_all_literals(erased<details::node> & n) {
	details::unit * asUnit = dynamic_cast<details::unit *>(&*n);
	if (asUnit != nullptr) {
		if (asUnit->tag == "") {
			details::literal_t const * originalAsLiteral = dynamic_cast<details::literal_t const *>(&asUnit->original_leaf);
			if (originalAsLiteral != nullptr) {
				asUnit->tag = string_to_c_name("literal_", originalAsLiteral->id);
			}
		}
	}
	for (auto & child : n->children) {
		tag_all_literals(child);
	}
}

// generate a production's .cpp and .hpp file
static cpp_generator::output_files generate_production_struct(std::string const & grammarName, std::list<std::string> const & namespaces, production const & p) {
	cpp_generator::output_files results;
	auto & headers = results.headers;
	auto & sources = results.sources;

	std::vector<std::string> subResults;
	auto representation = compute_document_representation(p.behavior);
	tag_all_literals(representation);
	std::set<std::string> forwardDeclarations;
	std::vector<std::string> builderDefinitions;
	bool fullyDefined;
	auto flattened = flatten_node(true, grammarName, representation, subResults, forwardDeclarations, namespaces, builderDefinitions, fullyDefined);
	std::stringstream header;
	std::stringstream source;
	std::string headerName = p.id + ".hpp";
	header << generated_notice;
	source << generated_notice;
	source << "#include \"" << headerName << "\"\n\n";
	source << "#include \"" << grammar_header_name(grammarName) << "\"\n\n";
	source << "#include \"parlex/details/document.hpp\"\n";
	source << "#include \"parlex/details/behavior.hpp\"\n\n";

	header << include_guard_start(p.id);
	header << "#include <optional>\n";
	header << "#include <variant>\n";
	header << "#include <vector>\n";
	header << "#include \"erased.hpp\"\n";
	header << "#include \"parlex/details/abstract_syntax_tree.hpp\"\n";
	header << "#include \"parlex/details/document.hpp\"\n\n";
	header << "#include \"" << grammarName << "_grammar.hpp\"\n\n";
	header << namespaces_start(namespaces) << "\n";
	covariant_invoke<void>(*flattened,
		[&](type const & value) {
			for (auto const & forwardDeclaration : forwardDeclarations) {
				header << "struct " << forwardDeclaration << ";\n";
				source << "#include \"" << forwardDeclaration << ".hpp\"\n";
			}
			if (!forwardDeclarations.empty()) {
				header << "\n";
				source << "\n";
			}
			for (auto const & subResult : subResults) {
				header << subResult << "\n\n";
			}
			if (!fullyDefined) {
				auto baseName = p.id + "_base";
				header << "typedef " << value.name << " " << baseName << ";\n\n";
				header << "struct " << p.id << ": " << baseName << " {\n";
				header << "\tstatic " << p.id << " build(std::u32string const & document, parlex::details::ast_node const & n);\n";
				header << "\texplicit " << p.id << "(" << baseName << " const & value) : " << baseName << "(value) {}\n";
				header << "};";

				source << "#include \"" << headerName << "\"\n\n";
				source << namespaces_start(namespaces) << "\n";
				source << p.id << " " << p.id << "::build(std::u32string const & document, parlex::details::ast_node const & n) {\n";
				source << "\tstatic auto const & b = " << grammarName << "_grammar::get()." << p.id << ".get_behavior();\n";
				source << "\tparlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };\n";
				source << "\treturn " << p.id << "(parlex::details::document::element<" << baseName << ">::build(document, b, w));\n";
				source << "}\n\n";
				source << namespaces_end(namespaces);
			}
			for (auto const & builderDefinition : builderDefinitions) {
				source << builderDefinition << "\n";
			}
		},
		[&](details::unit const & value) {
			header << "struct " << p.id << " {\n";
			header << "\tstatic " << p.id << " build(std::u32string const & document, parlex::details::ast_node const & n) { return " << p.id << "(); }\n";
			header << "};";
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
	header << "#include \"parlex/builder.hpp\"\n";
	header << "#include \"parlex/details/grammar.hpp\"\n\n";
	header << "#include \"_" << name << "_literals.hpp\"\n";
	header << namespaces_start(namespaces) << "\n";
	header << "class " << fullName << " : public parlex::details::grammar {\n";
	header << "public:\n";
	header << "\tstatic " << fullName << " const & get() {\n";
	header << "\t\tstatic " << fullName << " value;\n";
	header << "\t\treturn value;\n";
	header << "\t}\n\n";
	header << generate_production_member_declarations(b);
	header << "private:\n";
	header << "\t" << fullName << "();\n\n";
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
		if (production.id == "PARENTHETICAL_INVOCATION") debugger();
		results.add(generate_production_struct(name, namespaces, production));
	}
	std::map<std::u32string, std::string> literalMap;
	results.add(generate_literals(name, namespaces, b, literalMap));
	results.add(generate_grammar(name, namespaces, b));

	return results;
}

} // namespace parlex
