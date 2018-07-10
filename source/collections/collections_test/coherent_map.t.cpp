#include "../coherent_map.hpp"

#include <random>

#include "gtest/gtest.h"

TEST(CoherentMap, test_construction) {
	collections::coherent_map<int, int> x;
}

TEST(CoherentMap, test_assign_one_0) {
	collections::coherent_map<int, int> x;
	x[0] = 0;
	ASSERT_EQ(1, x.size());
}

TEST(CoherentMap, test_implicit_construction) {
	collections::coherent_map<int, int> x;
	EXPECT_EQ(0, x[0]);
}

TEST(CoherentMap, test_assign_one_1337) {
	collections::coherent_map<int, int> x;
	x[0] = 1337;
	EXPECT_EQ(1337, x[0]);
}

TEST(CoherentMap, test_erase_one) {
	collections::coherent_map<int, int> x;
	x[0] = 1337;
	x.erase(0);
	ASSERT_EQ(0, x.size());
}

TEST(CoherentMap, test_iterate_zero) {
	collections::coherent_map<int, int> x;
	EXPECT_EQ(x.begin(), x.end());
}

TEST(CoherentMap, test_iterate_one) {
	collections::coherent_map<int, int> x;
	x[0] = 0;
	for (auto const & entry : x) {
		ASSERT_EQ(entry.first, entry.second);
	}
}

TEST(CoherentMap, test_iterate_many) {
	collections::coherent_map<int, int> x;
	for (auto i = 0; i < 1000000; ++i) {
		x[i] = 999999 - i;
	}
	for (auto const & entry : x) {
		ASSERT_EQ(999999 - entry.first, entry.second);
	}
}

TEST(CoherentMap, test_iterate_many_strings) {
	collections::coherent_map<int, std::string> x;
	for (auto i = 0; i < 1000000; ++i) {
		x[i] = std::to_string(i);
	}
	for (auto const & entry: x) {
		ASSERT_EQ(std::to_string(entry.first), entry.second);
	}
}

TEST(CoherentMap, test_find_many_strings) {
	collections::coherent_map<int, std::string> x;
	for (auto i = 0; i < 1000000; ++i) {
		x[i] = std::to_string(i);
	}
	for (auto i = 0; i < 1000000; ++i) {
		auto entry = *x.find(i);
		ASSERT_EQ(std::to_string(entry.first), entry.second);
	}
}

TEST(CoherentMap, test_random_insert_one_many) {
	std::vector<int> numbers;
	numbers.resize(10000);
	for (auto i = 0; i < 10000; ++i) {
		numbers[i] = i;
	}
	std::mt19937 g;
	shuffle(numbers.begin(), numbers.end(), g);

	collections::coherent_map<int, std::string> x;
	for (auto i = 0; i < 10000; ++i) {
		auto j = numbers[i];
		auto const result = x.insert(make_pair(j, std::to_string(j)));
		ASSERT_EQ(true, result.second);
	}

	for (auto i = 0; i < 10000; ++i) {
		auto entry = *x.find(i);
		ASSERT_EQ(std::to_string(entry.first), entry.second);
	}
}

TEST(CoherentMap, test_insert_many_one) {
	std::vector<std::pair<int, int>> data{std::make_pair(0, 1337)};
	collections::coherent_map<int, int> x;
	ASSERT_EQ(1, x.insert_many(data.begin(), data.end()));
	EXPECT_EQ(1337, x[0]);
}

TEST(CoherentMap, test_insert_many_two) {
	std::vector<std::pair<int, int>> data{std::make_pair(0, 0), std::make_pair(1, 1)};
	collections::coherent_map<int, int> x;
	ASSERT_EQ(2, x.insert_many(data.begin(), data.end()));
	EXPECT_EQ(0, x[0]);
	EXPECT_EQ(1, x[1]);
}

TEST(CoherentMap, test_insert_many_two_reversed) {
	std::vector<std::pair<int, int>> data{std::make_pair(1, 1), std::make_pair(0, 0)};
	collections::coherent_map<int, int> x;
	ASSERT_EQ(2, x.insert_many(data.begin(), data.end()));
	EXPECT_EQ(0, x[0]);
	EXPECT_EQ(1, x[1]);
}

TEST(CoherentMap, test_random_insert_many_many) {
	std::vector<int> numbers;
	numbers.resize(1000000);
	for (auto i = 0; i < 1000000; ++i) {
		numbers[i] = i;
	}
	std::mt19937 g;
	shuffle(numbers.begin(), numbers.end(), g);

	std::vector<std::pair<int, std::string>> data;
	for (auto i = 0; i < 1000000; ++i) {
		auto j = numbers[i];
		data.emplace_back(j, std::to_string(j));
	}

	collections::coherent_map<int, std::string> x;
	ASSERT_EQ(1000000, x.insert_many(data.begin(), data.end()));

	for (auto i = 0; i < 1000000; ++i) {
		auto entry = *x.find(i);
		ASSERT_EQ(std::to_string(entry.first), entry.second);
	}
}

TEST(CoherentMap, test_random_assign_many_then_insert_many_then_find) {
	std::vector<int> numbers;
	numbers.resize(1000000);
	for (auto i = 0; i < 1000000; ++i) {
		numbers[i] = i;
	}
	std::mt19937 g;
	shuffle(numbers.begin(), numbers.end(), g);

	std::vector<std::pair<int, std::string>> data;
	for (auto i = 0; i < 1000000; ++i) {
		auto j = numbers[i];
		data.emplace_back(j, std::to_string(j));
	}

	collections::coherent_map<int, std::string> x;
	for (auto i = 0; i < 500; ++i) {
		auto const j = data[i];
		x[j.first] = j.second;
	}

	ASSERT_EQ(999500, x.insert_many(data.begin(), data.end()));

	for (auto i = 0; i < 1000000; ++i) {
		auto entry = *x.find(i);
		ASSERT_EQ(std::to_string(entry.first), entry.second);
	}
}

TEST(CoherentMap, test_random_insert_many_then_iterate) {
	std::vector<int> numbers;
	numbers.resize(1000000);
	for (auto i = 0; i < 1000000; ++i) {
		numbers[i] = i;
	}
	std::mt19937 g;
	shuffle(numbers.begin(), numbers.end(), g);

	std::vector<std::pair<int, std::string>> data;
	for (auto i = 0; i < 1000000; ++i) {
		auto j = numbers[i];
		data.emplace_back(j, std::to_string(j));
	}

	collections::coherent_map<int, std::string> x;
	ASSERT_EQ(1000000, x.insert_many(data.begin(), data.end()));

	size_t counter = 0;
	for (auto const & entry: x) {
		ASSERT_EQ(counter++, entry.first);
	}
}

TEST(CoherentMap, test_erase_one_pointer_key) {
	collections::coherent_map<void const *, int> x;
	x[nullptr] = 1337;
	x.erase(nullptr);
	ASSERT_EQ(0, x.size());
}

TEST(CoherentMap, test_iterator_subtraction) {
	collections::coherent_map<int, int> x;
	for (auto i = 0; i < 10; ++i) {
		x[i] = i;
	}
	auto i = x.begin();
	++i;
	++i;
	EXPECT_EQ(2, i - x.begin());
	i = i - 2;
	EXPECT_EQ(0, i - x.begin());
}

TEST(CoherentMap, test_erase_many_all) {
	collections::coherent_map<int, int> x;
	std::set<int> remove;
	for (auto i = 0; i < 5; ++i) {
		x[i] = i;
		remove.insert(i);
	}
	ASSERT_EQ(5, x.erase_many(remove.begin(), remove.end()));
	EXPECT_EQ(0, x.size());
}


TEST(CoherentMap, test_erase_many_strict_subset) {
	collections::coherent_map<int, int> x;
	for (auto i = 0; i < 5; ++i) {
		x[i] = i;
	}
	std::set<int> remove;
	remove.insert(1);
	remove.insert(3);
	ASSERT_EQ(2, x.erase_many(remove.begin(), remove.end()));
	EXPECT_EQ(3, x.size());
}

TEST(CoherentMap, test_erase_many_arbitrary) {
	collections::coherent_map<int, int> x;
	for (auto i = 0; i < 5; ++i) {
		x[i] = i;
	}
	std::set<int> remove;
	remove.insert(1);
	remove.insert(5);
	ASSERT_EQ(1, x.erase_many(remove.begin(), remove.end()));
	EXPECT_EQ(4, x.size());
}

TEST(CoherentMap, test_emplace_non_copyable) {
	struct a {
		int v;
		explicit a(int v) : v(v) {}
		a(a const & copy) = delete;
		a(a && move) = default;
		bool operator<(a const & rhs) const {
			return v < rhs.v;
		}
	};

	collections::coherent_map<a, a> x;
	x.emplace(std::piecewise_construct, std::forward_as_tuple(0), std::forward_as_tuple(0));
}

TEST(CoherentMap, test_end_iterator) {
	collections::coherent_map<int, int> x;
	EXPECT_EQ(x.end(), x.find(0));
	EXPECT_EQ(x.end(), x.lower_bound(0));
}

TEST(CoherentMap, zero_erase_many) {
	collections::coherent_map<int, int> x;
	x[1] = 1;
	std::vector<int> toErase{0, 2};
	EXPECT_EQ(0, x.erase_many(toErase.begin(), toErase.end()));
	EXPECT_EQ(1, x.size());
}
