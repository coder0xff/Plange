#ifndef INCLUDING_MPL_HAS_TYPE_MEMBER_HPP
#define INCLUDING_MPL_HAS_TYPE_MEMBER_HPP

// Example usage:
//
// MPL_MAKE_HAS_TYPE_MEMBER(value_type);
// static_assert(has_type_member_value_type<std::string>, "std::string has value_type type member");
// static_assert(!has_type_member_value_type<int>, "int has not value_type type member");

#include <type_traits>

// eventually update to use std::is_detected
#define MPL_MAKE_HAS_TYPE_MEMBER(name) \
struct has_type_member##name_impl { \
	template<typename T> static std::true_type impl(typename T::name*); \
	template<typename> static std::false_type impl(...); \
}; \
template<typename T> constexpr bool has_type_member##name = decltype(has_type_member##name_impl::impl<T>(nullptr))::value;

#define INCLUDED_MPL_HAS_TYPE_MEMBER_HPP
#elif !defined(INCLUDED_MPL_HAS_TYPE_MEMBER_HPP)
#	error circular inclusion
#endif
