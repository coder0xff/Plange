#ifndef CONCRETE_SYNTAX_TREE_HPP
#define CONCRETE_SYNTAX_TREE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "abstract_syntax_semilattice.hpp"
#include "behavior.hpp"
#include "erased.hpp"
#include "match.hpp"
#include "permutation.hpp"

namespace parlex::details::concrete_syntax_tree {

	template<typename T>
	T build(transition const & t, abstract_syntax_semilattice const & ass);

	template<typename T>
	void build(std::optional<T> & value, match const & m, abstract_syntax_semilattice const & ass) {
		std::optional<T> temp = T::build(i);
		if (temp.has_value()) {
			value = std::optional<T>(temp.value());
		}
	}

	template<typename T>
	void build(std::optional<std::vector<T>> & value, ast_iterator & i) {
		std::vector<T> results;
		while (true) {
			std::optional<T> element;
			build(element, i);
			if (element.has_value()) {
				results.push_back(element.value());
			}
			else {
				break;
			}
		}
		if (results.size() > 0) { value = results; }
	}

	struct tuple_element_builder {
		std::vector<match>::iterator & i;
		explicit tuple_element_builder(ast_iterator & i) : i(i) {}

		template<typename T>
		T operator()() {
			std::optional<T> temp;
			build(temp, i);
			return temp.value();
		}
	};

	template<typename... Ts>
	void build(std::optional<std::tuple<Ts...>> & value, ast_iterator & i) {
		auto originalI = i;
		tuple_element_builder functor(i);
		try {
			value = mpl::map_v<std::tuple<Ts...>>::map(functor);
		}
		catch (std::bad_optional_access) {
			i = originalI;
		}
	}

	template<typename... Ts>
	struct variant_builder {
		typedef std::variant<Ts...> TVariant;
		std::vector<match>::iterator & i;
		variant_builder(ast_iterator & i) : i(i) {}

		template<typename TAccumulator, typename THead>
		std::optional<TVariant> operator()(TAccumulator const & accumulator) {
			if (accumulator.has_value()) {
				return accumulator;
			}
			std::optional<THead> temp;
			build(temp, i);
			if (temp.has_value()) {
				return std::optional<TVariant>(TVariant(temp.value()));
			}
			return accumulator;
		}

	};

	template<typename... Ts>
	void build(std::variant<Ts...> & value, match const & m, abstract_syntax_semilattice const & ass) {
		variant_builder<Ts...> functor(i);
		value = mpl::fold_v<mpl::list<Ts...>>::invoke(functor, std::optional<std::variant<Ts...>>());
	}

	template<typename T>
	void build(std::optional<erased<T>> & value, ast_iterator & i) {
		std::optional<T> temp;
		build(temp, i);
		if (!temp.has_value()) {
			value = std::optional<erased<T>>();
			return;
		}
		value = std::optional<erased<T>>(temp.value());
	}


}

#endif //CONCRETE_SYNTAX_TREE_HPP