#ifndef MOVER_HPP
#define MOVER_HPP

#include "../mpl/mpl_is_movable.hpp"
#include "../mpl/mpl_is_copyable.hpp"
#include "../mpl/mpl_sfinae.hpp"

namespace collections::detail {

template<typename T>
void mover(T* const dst, T* const src, SFINAE_PARAM(mpl::IS_MOVABLE<T>)) {
	new (dst) T(std::move(*src));
	src->~T();
}

template<typename T>
void mover(T* const dst, T* const src, SFINAE_PARAM(!mpl::IS_MOVABLE<T> && mpl::IS_COPYABLE<T>)) {
	new (dst) T(*src);
	src->~U();
}

}

#endif //MOVER_HPP