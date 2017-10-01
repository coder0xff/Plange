#include "../mpl_indices.hpp"

#include "../mpl_equals.hpp"

static_assert(mpl::equals<mpl::drop_indices<0, mpl::indices<3, 1, 4, 5, 2>>, mpl::indices<3, 1, 4, 5, 2>>, "");

static_assert(mpl::equals<mpl::drop_indices<2, mpl::indices<3, 1, 4, 5, 2>>, mpl::indices<4, 5, 2>>, "");

static_assert(mpl::equals<mpl::indices_of<std::tuple<>>, mpl::indices<>>, "");

static_assert(mpl::equals<mpl::indices_of<std::tuple<int, float>>, mpl::indices<0, 1>>, "");