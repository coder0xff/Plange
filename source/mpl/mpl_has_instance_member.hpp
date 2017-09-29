#ifndef INCLUDING_MPL_HAS_INSTANCE_MEMBER_HPP
#define INCLUDING_MPL_HAS_INSTANCE_MEMBER_HPP

// Example usage:
//
// MPL_MAKE_has_instance_member(value_type);
// static_assert(has_instance_member_value_type<std::string>, "std::string has value_type type member");
// static_assert(!has_instance_member_value_type<int>, "int has not value_type type member");

#include <type_traits>

#define MPL_MAKE_HAS_INSTANCE_MEMBER(name) \
struct has_instance_member_##name_impl { \
	template<typename T> \
	static std::true_type impl(decltype(((T*)nullptr)->name)*); \
	template<typename> \
	static std::false_type impl(...); \
}; \
template<typename T> \
constexpr bool has_instance_member_##name = decltype(has_instance_member_##name_impl::impl<T>(nullptr))::value;

#define INCLUDED_MPL_HAS_INSTANCE_MEMBER_HPP
#elif !defined(INCLUDED_MPL_has_instance_member_HPP)
#	error circular inclusion
#endif
