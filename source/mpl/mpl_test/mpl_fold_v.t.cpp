#include "../mpl_fold_v.hpp"

#include <cassert>
#include "gtest/gtest.h"

#include "../mpl_equals.hpp"
#include "../mpl_list.hpp"
#include "../mpl_utils.hpp"

namespace test1 {
	struct functor {
		template <typename TAccumulator, typename THead>
		int operator()(TAccumulator const & accumulator) {
			return accumulator * multiplier + sizeof(THead);
		}

		int multiplier;
	};

	void invoke() {
		functor f;
		f.multiplier = 2;
		auto result = mpl::fold_v<mpl::list<int, char>>::invoke(f, 100);
		static_assert(mpl::equals<decltype(result), int>, "");
		assert(result == 409); // (100 * 2 + sizeof(int)) * 2 + sizeof(char) == 409
	}
}

TEST(mplTest, fold_v_1) {
	test1::invoke();
}

namespace test2 {
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

TEST(mplTest, fold_v_2) {
	test2::invoke();
}