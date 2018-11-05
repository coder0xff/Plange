#ifndef INCLUDED_PARLEX_DOCUMENT_HPP
#define INCLUDED_PARLEX_DOCUMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"
#include "mpl_fold_vx.hpp"

#include "parlex/builder.hpp"
#include "parlex/detail/abstract_syntax_semilattice.hpp"

namespace parlex::detail::document {

	struct walk {
		std::vector<ast_node>::const_iterator pos;
		std::vector<ast_node>::const_iterator const end;
	};

	template<typename T>
	struct text {
		size_t document_position;
		size_t consumed_character_count;
	};

	template<typename T>
	struct element {
		static T build(node const * b, walk & w) {
			return T::build(b, w);
		}
	};

	template<typename T>
	struct element<text<T>> {
		static text<T> build(node const * b, walk & w) {
			text<T> result{ w.pos->document_position, w.pos->consumed_character_count };
			++w.pos;
			return result;
		}
	};

	template<>
	struct element<bool> {
		static bool build(node const * b, walk & w) {
			auto const checkPos = w.pos;
			for (; w.pos != w.end && b->follow_or_nullptr(w.pos->l) != nullptr; ++w.pos) {}
			return w.pos != checkPos;
		}
	};

	template<typename T>
	struct element<val<T>> {
		static val<T> build(node const * b, walk & w) {
			auto const * asLeaf = dynamic_cast<leaf const *>(b);
			throw_assert(asLeaf != nullptr);
			throw_assert(asLeaf == w.pos->l);
			val<T> temp = T::build(*w.pos++);
			return temp;
		}
	};

	template<typename T>
	struct element<std::vector<T>> {
		static std::vector<T> build(node const * b, walk & w) {
			auto const * asRepetition = dynamic_cast<repetition const *>(b);
			throw_assert(asRepetition != nullptr);
			auto loneChild = &*asRepetition->children[0];
			std::vector<T> result;
			for (; w.pos != w.end && b->follow_or_nullptr(w.pos->l) == loneChild; ) {
				auto const checkPos = w.pos;
				result.push_back(element<T>::build(loneChild, w));
				throw_assert(w.pos > checkPos);
			}
			return result;
		}
	};

	template<typename T>
	struct element<std::optional<T>> {
		static std::optional<T> build(node const * b, walk & w) {
			auto const & asOptional = dynamic_cast<optional const *>(b);
			throw_assert(asOptional != nullptr);
			if (w.pos != w.end) {
				auto loneChild = &*asOptional->children[0];
				auto const followedChild = b->follow_or_nullptr(w.pos->l);
				if (followedChild != nullptr) {
					throw_assert(followedChild == loneChild);
					return std::optional<T>(element<T>::build(loneChild, w));
				}
			}
			return std::optional<T>();
		}
	};

	template<typename... Ts>
	struct variant_helper {
		typedef std::variant<Ts...> t_variant;
		typedef std::map<node const *, t_variant(*)(node const * b, walk & w)> t_table;

		template<typename T>
		static t_variant wrapper(node const * b, walk & w);

		template<typename T>
		t_table operator()(t_table && accumulator, val<node> const & b) {
			accumulator[&*b] = &wrapper<T>;
			return accumulator;
		}

	};

	template <typename ... Ts>
	template <typename T>
	typename variant_helper<Ts...>::t_variant variant_helper<Ts...>::wrapper(node const * b, walk & w) {
		T a = element<T>::build(b, w);
		auto result = t_variant(a);
		return result;
	}

	template<typename... Ts>
	struct element<std::variant<Ts...>> {
		static std::variant<Ts...> build(node const * b, walk & w) {
			using t_variant = std::variant<Ts...>;
			using functor_t = variant_helper<Ts...>;
			auto const & childBehaviors = b->children;
			auto functor = functor_t();
			//TODO: cache this
			typename functor_t::t_table table = mpl::fold_vx<mpl::list<Ts...>>(functor, typename functor_t::t_table(), childBehaviors);
			auto child = b->follow_or_nullptr(w.pos->l);
			typename functor_t::t_table::iterator i = table.find(child);
			throw_assert(i != table.end());
			return i->second(child, w);
		}
	};

}

#endif // INCLUDED_PARLEX_DOCUMENT_HPP