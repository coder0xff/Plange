// So CMake configure works

#include <map>

#include "mpl_apply.hpp"
#include "mpl_bind.hpp"
#include "mpl_equals.hpp"
#include "mpl_fold.hpp"
#include "mpl_fold_i.hpp"
#include "mpl_fold_v.hpp"
#include "mpl_list.hpp"
#include <cassert>
#include "../utilities/utils.hpp"

static_assert(!mpl::equals<int, float>, "");

static_assert(mpl::equals<std::map<int, float>, mpl::apply<std::map, std::tuple<int, float>>>, "");

static_assert(mpl::equals<std::map<int, float>, mpl::bind<std::map, int, mpl::bind_point<0>>::invoke<float>>, "");

namespace test1 {
	template <typename T, typename U>
	struct test_impl {};

	template <int V, typename U>
	struct test_impl<std::integral_constant<int, V>, U> {
		using result = std::integral_constant<int, V + sizeof(U)>;
	};

	template <typename T, typename U>
	using test = typename test_impl<T, U>::result;

	using result = mpl::fold<test, std::integral_constant<int, 0>, std::tuple<float, char>>;
	static_assert(mpl::equals<result, std::integral_constant<int, 5>>, "");
}

namespace test2 {
	template <typename T, size_t Index, typename U>
	struct test_impl {};

	template <int V, size_t Index, typename U>
	struct test_impl<std::integral_constant<int, V>, Index, U> {
		using result = std::integral_constant<int, V + sizeof(U) + Index>;
	};

	template <typename T, size_t Index, typename U>
	using test = typename test_impl<T, Index, U>::result;

	using result = mpl::fold_i<test, std::integral_constant<int, 0>, std::tuple<float, char>>;
	static_assert(mpl::equals<result, std::integral_constant<int, 6>>, "");
}

namespace test3 {
	struct functor {
		template<typename TAccumulator, typename THead>
		auto operator()(TAccumulator const & accumulator) {
			return accumulator * multiplier + sizeof(THead);
		}

		int multiplier;
	};

	void invoke() {
		functor f;
		f.multiplier = 2;
		auto result = mpl::fold_v<mpl::list<int, char>>::invoke(f, 100);
		static_assert(mpl::equals<decltype(result), unsigned int>, "");
		assert(result == 409);
	}
	
}

namespace test4 {
	struct functor {
		template<typename TAccumulator, typename THead>
		auto operator()(TAccumulator const & acc) {
			return make_tuple((THead)sizeof(THead), acc);
		}
	};

	void invoke() {
		functor f;
		auto result = mpl::fold_v<mpl::list<int, char>>::invoke(f, std::tuple<>());
		static_assert(mpl::equals<decltype(result), std::tuple<char, std::tuple<int, std::tuple<>>>>, "");
		assert(result == std::make_tuple(char(1), std::make_tuple(int(4), std::make_tuple())));
	}
}

int main() {
	test3::invoke();
	test4::invoke();
}