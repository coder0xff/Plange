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
#include "utf.hpp"

namespace parlex::details::document {

	template<typename T>
	struct built_in_terminal {};

	struct walk {
		ast_node::const_iterator pos;
		ast_node::const_iterator const end;
	};

	template<typename T>
	struct element {
		static T build(std::u32string const & document, behavior::node const & b, walk & w) {
			return T::build(document, b, w);
		}
	};

	template<typename T>
	struct element<built_in_terminal<T>> {
		static built_in_terminal<T> build(std::u32string const & document, behavior::node const & b, walk & w) {
			*w.pos++;
			return built_in_terminal<T>();
		}
	};

	template<>
	struct element<bool> {
		static bool build(std::u32string const & document, behavior::node const & b, walk & w) {
			auto checkPos = w.pos;
			for (; w.pos != w.end && b.follow(w.pos->leaf) != nullptr; ++w.pos);
			return w.pos != checkPos;
		}
	};

	template<>
	struct element<int> {
		static int build(std::u32string const &, behavior::node const & b, walk & w) {
			auto const * asRepetition = dynamic_cast<behavior::repetition const *>(&b);
			assert(asRepetition != nullptr);
			auto const & loneChild = asRepetition->get_children()[0];
			for (; w.pos != w.end && loneChild->follow(w.pos->leaf) != nullptr; ++w.pos);
			int result = w.pos->children.size();
			++w.pos;
			return result;
		}
	};

	template<>
	struct element<std::string> {
		static std::string build(std::u32string const & document, behavior::node const & b, walk & w) {
			assert(w.pos != w.end);
			auto result = to_utf8(document.substr(w.pos->document_position, w.pos->consumed_character_count));
			++w.pos;
			return result;
		}
	};

	template<typename T>
	struct element<erased<T>> {
		static erased<T> build(std::u32string const & document, behavior::node const & b, walk & w) {
			auto const * asLeaf = dynamic_cast<behavior::leaf const *>(&b);
			assert(asLeaf != nullptr);
			assert(asLeaf == w.pos->leaf);
			return T::build(document, *w.pos++);
		}
	};

	template<typename T>
	struct element<std::vector<T>> {
		static std::vector<T> build(std::u32string const & document, behavior::node const & b, walk & w) {
			auto const * asRepetition = dynamic_cast<behavior::repetition const *>(&b);
			assert(asRepetition != nullptr);
			behavior::node const & loneChild = *asRepetition->get_children()[0];
			std::vector<T> result;
			for (; w.pos != w.end && b.follow(w.pos->leaf) == &loneChild; ) {
				auto checkPos = w.pos;
				result.push_back(element<T>::build(document, loneChild, w));
				assert(w.pos > checkPos);
			}
			return result;
		}
	};

	template<typename T>
	struct element<std::optional<T>> {
		static std::optional<T> build(std::u32string const & document, behavior::node const & b, walk & w) {
			auto const & asOptional = dynamic_cast<behavior::optional const *>(&b);
			assert(asOptional != nullptr);
			if (w.pos != w.end) {
				behavior::node const * loneChild = &*asOptional->get_children()[0];
				behavior::node const * followedChild = b.follow(w.pos->leaf);
				if (followedChild != nullptr) {
					assert(followedChild == loneChild);
					return std::optional<T>(element<T>::build(document, *loneChild, w));
				}
			}
			return std::optional<T>();
		}
	};

	template<typename... Ts>
	struct variant_helper {
		typedef std::variant<Ts...> TVariant;
		typedef std::unordered_map<behavior::node const *, TVariant(*)(std::u32string const &, behavior::node const & b, walk & w)> TTable;

		template<typename T>
		static TVariant wrapper(std::u32string const & document, behavior::node const & b, walk & w) {
			return TVariant(element<T>::build(document, b, w));
		}

		template<typename T>
		TTable operator()(TTable && accumulator, erased<behavior::node> const & b) {
			accumulator[&*b] = &wrapper<T>;
			return accumulator;
		}

	};

	template<typename... Ts>
	struct element<std::variant<Ts...>> {
		static std::variant<Ts...> build(std::u32string const & document, behavior::node const & b, walk & w) {
			assert(dynamic_cast<behavior::choice const *>(&b) != nullptr);
			using TVariant = std::variant<Ts...>;
			using functor_t = variant_helper<Ts...>;
			auto const & childBehaviors = b.get_children();
			auto functor = functor_t();
			//TODO: cache this
			typename functor_t::TTable table = mpl::fold_vx<mpl::list<Ts...>>(functor, functor_t::TTable(), childBehaviors);
			behavior::node const * child = b.follow(w.pos->leaf);
			assert(child != nullptr);
			typename functor_t::TTable::iterator i = table.find(child);
			assert(i != table.end());
			return i->second(document, *child, w);
		}
	};

}

#endif //DOCUMENT_HPP