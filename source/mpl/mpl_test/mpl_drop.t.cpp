#include "../mpl_drop.hpp"
#include "../mpl_equals.hpp"
#include "../mpl_list.hpp"

static_assert(mpl::EQUALS<mpl::list<char, int, float>, mpl::drop<0, mpl::list<char, int, float>>>, "");

//static_assert(mpl::equals<mpl::list<int, float>, mpl::drop<1, mpl::list<char, int, float>>>, "");

//static_assert(mpl::equals<mpl::list<float>, mpl::drop<2, mpl::list<char, int, float>>>, "");
