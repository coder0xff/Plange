#ifndef BEHAVIOR_HPP
#define BEHAVIOR_HPP

#include <optional>

#include "erased.hpp"
#include "match.hpp"

#include "mpl_apply.hpp"
#include "mpl_fold_value.hpp"
#include "mpl_map_values.hpp"

#include "parlex/details/nfa.hpp"
#include "parlex/details/recognizer.hpp"

namespace parlex {
namespace details {

class raw_state_machine;

namespace behavior {

class leaf;
using nfa2 = nfa<leaf const *, size_t>;
std::string nfa2_to_dot(nfa2 const & nfa);

class node {
public:
	virtual ~node() = default;
	using children_t = std::vector<erased<node>>;
	std::string tag;
	void add_child(erased<node> child);
	children_t const& get_children() const;
	virtual nfa2 to_nfa() const = 0;
	std::string to_dot() const;
	nfa2 compile() const;
protected:
	node() = default;

	node(node const & other);


	children_t children;
	node * parent;
};

class leaf final : public node {
public:
	explicit leaf(recognizer const & r);
	recognizer const & r;
	std::string const & id;
private:
	nfa2 to_nfa() const override;
};

class choice final : public node {
public:
	nfa2 to_nfa() const override;
};

class optional final : public node {
public:
	nfa2 to_nfa() const override;
};

class repetition final : public node {
public:
	nfa2 to_nfa() const override;
};

class sequence final : public node {
public:
	nfa2 to_nfa() const override;
};

template<typename T>
std::optional<std::vector<T>> build_vector(std::vector<match>::iterator & i, node const & behavior) {
	std::vector<T> results;
	while (true) {
		std::optional<T> element = T::build(i, behavior.get_children()[0]);
		if (element.has_value()) {
			results.push_back(element.value());
		} else {
			break;
		}
	}
	return results;
}

template<typename T>
std::optional<T> build_optional(std::vector<match>::iterator & i, node const & behavior) {
	return T::build(i, behavior.get_children()[0]);
}

struct tuple_element_builder {
	std::vector<match>::iterator & i;
	tuple_element_builder(std::vector<match>::iterator & i) : i(i) {}

	template<typename T>
	T operator()(node const & behavior) {
		std::optional<T> result = T::build(i, behavior);
		if (result.has_value()) {
			return result.value();
		} else {
			throw this;
		}
	}
};

template<typename TTuple>
std::optional<TTuple> build_tuple(std::vector<match>::iterator & i, node const & behavior) {
	auto originalI = i;
	tuple_element_builder functor(i);
	try {
		TTuple results = mpl::apply<mpl::map_vector_values, TTuple>::map(functor, behavior.get_children());
		return std::optional<TTuple>(results);
	} catch (tuple_element_builder *) {
		i = originalI;
		return std::optional<TTuple>();
	}
}

template<typename TVariant>
struct variant_builder {
	std::vector<match>::iterator & i;
	node const & behavior;
	variant_builder(std::vector<match>::iterator & i, node const & behavior) : i(i), behavior(behavior) {}

	template<typename T>
	std::optional<TVariant> operator()(std::optional<TVariant> const & accumulator) {
		if (accumulator.has_value()) {
			return accumulator;
		}
		std::optional<T> maybeResult = T::build(i, behavior);
		if (maybeResult.has_value()) {
			return std::optional<TVariant>(TVariant(maybeResult.value()));
		} else {
			return std::optional<TVariant>();
		}
	}

};
template<typename TVariant>
std::optional<TVariant> build_variant(std::vector<match>::iterator & i, node const & behavior) {
	variant_builder<TVariant> functor(i, behavior);
	return mpl::apply<mpl::fold_value, TVariant>::fold(functor, std::optional<TVariant>());
}

} // namespace behavior
} // namespace details
} // namespace parlex

#endif //BEHAVIOR_HPP
