#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <cassert>
#include <optional>
#include <variant>
#include <vector>

#include "abstract_syntax_semilattice.hpp"
#include "behavior.hpp"
#include "erased.hpp"
#include "match.hpp"
#include "permutation.hpp"

#include "mpl_fold_vx.hpp"

namespace parlex::details::document {

	behavior::node const & follow(behavior::node const & a, behavior::leaf const & b) {
		return *a.follow(&b);
	}

	template<typename T>
	struct element {

	};

	//literals only have one instance, so we work in pointers to that instance
	template<typename T>
	struct element<T const *> {
		static T const * build(behavior::node const & b, ast_node const & n) {
			return T::get();
		}
	};

	template<typename T>
	struct element<erased<T>> {
		static T build(behavior::node const & b, ast_node const & n) {
			auto asLeafPtr = dynamic_cast<behavior::leaf const *>(&b);
			assert(asLeafPtr != nullptr);
			return T::build(n);
		}
	};

	template<typename T>
	struct element<std::vector<T>> {
		static std::vector<T> build(behavior::node const & b, ast_node const & n) {
			assert(dynamic_cast<behavior::repetition const *>(&b) != nullptr);
			behavior::node const & bChild = *b.get_children()[0];
			std::vector<T> result;
			for (ast_node const & child : n.children) {
				assert(b.can_follow(child.leaf));
				result.push_back(element<T>::build(bChild, child));
			}
			return result;
		}
	};

	template<typename T>
	struct element<std::optional<T>> {
		static std::optional<T> build(behavior::node const & b, ast_node const & n) {
			assert(dynamic_cast<behavior::optional const *>(&b) != nullptr);
			behavior::node const & bChild = *b.get_children()[0];
			for (ast_node const & child : n) {
				if (b.can_follow(child.leaf)) {
					return std::optional<T>(element<T>::build(bChild, child));
				}
			}
			return std::optional<T>();
		}
	};

	template<typename... Ts>
	struct variant_builder {
		typedef std::variant<Ts...> TVariant;
		ast_node const * n;

		variant_builder(ast_node const * n) : n(n) {}

		template<typename THead>
		std::optional<TVariant> operator()(std::optional<TVariant> const & accumulator, erased<behavior::node> const & b) {
			if (accumulator.has_value()) {
				return accumulator;
			}
			if (b->can_follow(n->leaf)) {
				return std::optional<TVariant>(TVariant(element<THead>::build(*b, *n)));
			}
			return accumulator;
		}

	};

	template<typename... Ts>
	struct element<std::variant<Ts...>> {
		static std::variant<Ts...> build(behavior::node const & b, ast_node const & n) {
			assert(dynamic_cast<behavior::choice const *>(&b) != nullptr);
			using TVariant = std::variant<Ts...>;
			auto const & childBehaviors = b.get_children();
			variant_builder<Ts...> functor = variant_builder<Ts...>(&n);
			return mpl::fold_vx<mpl::list<Ts...>>(functor, std::optional<TVariant>(), childBehaviors).value();
		}
	};

// 	template<typename T>
// 	void build_optional(std::optional<T> const ** value, ast_node const & n, behavior::node const & b) {
// 		T const * wrapped;
// 		build<T>(&wrapped, n, b(0));
// 		*value = new std::optional<T>(*wrapped);
// 	}
// 
// 	template<typename T>
// 	void build_vector(std::vector<T> const ** value, ast_node const & n, behavior::node const & b) {
// 		
// 	}
// 
// 	template<typename T>
// 	void build(std::optional<std::vector<T>> & value, ast_iterator & i) {
// 		std::vector<T> results;
// 		while (true) {
// 			std::optional<T> element;
// 			build(element, i);
// 			if (element.has_value()) {
// 				results.push_back(element.value());
// 			}
// 			else {
// 				break;
// 			}
// 		}
// 		if (results.size() > 0) { value = results; }
// 	}
// 
// 	struct tuple_element_builder {
// 		std::vector<match>::iterator & i;
// 		explicit tuple_element_builder(ast_iterator & i) : i(i) {}
// 
// 		template<typename T>
// 		T operator()() {
// 			std::optional<T> temp;
// 			build(temp, i);
// 			return temp.value();
// 		}
// 	};
// 
// 	template<typename... Ts>
// 	void build(std::optional<std::tuple<Ts...>> & value, ast_iterator & i) {
// 		auto originalI = i;
// 		tuple_element_builder functor(i);
// 		try {
// 			value = mpl::map_v<std::tuple<Ts...>>::map(functor);
// 		}
// 		catch (std::bad_optional_access) {
// 			i = originalI;
// 		}
// 	}
// 
// 	template<typename... Ts>
// 	struct variant_builder {
// 		typedef std::variant<Ts...> TVariant;
// 		std::vector<match>::iterator & i;
// 		variant_builder(ast_iterator & i) : i(i) {}
// 
// 		template<typename TAccumulator, typename THead>
// 		std::optional<TVariant> operator()(TAccumulator const & accumulator) {
// 			if (accumulator.has_value()) {
// 				return accumulator;
// 			}
// 			std::optional<THead> temp;
// 			build(temp, i);
// 			if (temp.has_value()) {
// 				return std::optional<TVariant>(TVariant(temp.value()));
// 			}
// 			return accumulator;
// 		}
// 
// 	};
// 
// 	template<typename... Ts>
// 	void build(std::variant<Ts...> & value, match const & m, abstract_syntax_semilattice const & ass) {
// 		variant_builder<Ts...> functor(i);
// 		value = mpl::fold_v<mpl::list<Ts...>>::invoke(functor, std::optional<std::variant<Ts...>>());
// 	}
// 
// 	template<typename T>
// 	void build(std::optional<erased<T>> & value, ast_iterator & i) {
// 		std::optional<T> temp;
// 		build(temp, i);
// 		if (!temp.has_value()) {
// 			value = std::optional<erased<T>>();
// 			return;
// 		}
// 		value = std::optional<erased<T>>(temp.value());
// 	}


}

#endif //DOCUMENT_HPP