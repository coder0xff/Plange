#include "parlex/cpp_generator.hpp"

#include <sstream>

#include "parlex/builder.hpp"
#include "parlex/details/builtins.hpp"


#include "parlex/details/behavior.hpp"
#include "dynamic_dispatch.hpp"

namespace parlex {

static std::string get_include_guard_name(std::string name) {
	for (auto & c : name) c = toupper(c);
	return name + "_HPP";
}

static std::string get_include_guard_open(std::string const & include_guard_name) {
	return "#ifndef " + include_guard_name + "\n#define" + include_guard_name + "\n";
}

static std::string get_include_guard_close(std::string const & include_guard_name) {
	return "#endif //" + include_guard_name;
}

static std::string add_include_guard(std::string const & text, std::string const & production_name) {
	auto include_guard_name = get_include_guard_name(production_name);
	return get_include_guard_open(include_guard_name) + "\n" + text + "\n" + get_include_guard_close(include_guard_name);
}

static std::string get_namespaces_open(std::vector<std::string> const & namespaces) {
	std::string result;
	for (auto const & n : namespaces) {
		result += "namespace " + n + " {";
	}
	return result;
}

static std::string get_namespaces_close(std::vector<std::string> const & namespaces) {
	std::string result;
	for (auto i = namespaces.rbegin(); i != namespaces.rend(); ++i) {
		result += "} // " + *i + "\n";
	}
	return result;
}

static std::string add_namespaces(std::string const & text, std::vector<std::string> const & namespaces) {
	return get_namespaces_open(namespaces) + "\n" + text + "\n" + get_namespaces_close(namespaces);
}

static std::string generate_grammar_hpp_code(std::string const & name, builder const & b, std::vector<std::string> const & namespaces) {
	std::stringstream result;
	result << "class " << name << " : public builder::grammar {\n";
	result << "public:\n";
	for (auto const & production : b.productions) {
		result << "\tbuilder::production " << production.id << ";\n";
	}
	result << "\n";
	result << "\t";
	throw std::logic_error("not implemented");
}

std::string node_to_cpp(details::node const & n, int indentLevel) {
	std::string indentString(std::string(indentLevel, '\t'));

	auto add_tag = [&]()
	{
		if (n.tag != "") {
			return enquote(n.tag) + ", ";
		}
		return std::string();
	};

	auto add_children = [&]()
	{
		std::stringstream ss;
		for (auto const & child : n.children) {
			ss << indentString;
			ss << '\t' << node_to_cpp(*child, indentLevel + 1);
			if (&*child != &**n.children.rbegin()) {
				ss << ",";
			}
			ss << '\n';
		}
		return ss.str();
	};

#define DO_AS(name)	[&](details::name##_t const & v) { return "parlex::" #name "(" + add_tag() + "{\n" + add_children() + indentString + "})"; }

	return dynamic_dispatch<std::string>(n,
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

std::string production_to_cpp(production const & p) {
	std::stringstream ss;
	ss << "parlex::production(" << enquote(p.id) << ",\n\t\t";
	ss << node_to_cpp(*p.behavior, 2);
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
		}
		else if (!p.filter) {
			ss << "parlex::filter_function()";
		}
		else {
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

std::string generate_grammar_builder(builder const & b) {
	std::stringstream ss;
	ss << "parlex::builder(" << enquote(b.root_id) << ", {\n";
	for (auto const & p : b.productions) {
		ss << "\t" << production_to_cpp(p);
		ss << ",\n";
	}
	ss << "})";
	return ss.str();
}



cpp_generator::output_files cpp_generator::generate(std::string const & name, builder const & b) {
	output_files results;
	auto & headers = results.headers;
	auto & sources = results.sources;

	sources[name + ".grammar_builder.cpp.inc"] = generate_grammar_builder(b);
	return results;
}

} // namespace parlex
