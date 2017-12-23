#include "gtest/gtest.h"
#include "../coherent_map.hpp"
#include <random>

TEST(CoherentMap, test00) {
	collections::coherent_map<int, int> x;
}

TEST(CoherentMap, test01) {
	collections::coherent_map<int, int> x;
	x[0] = 0;
	ASSERT_EQ(1, x.size());
}

TEST(CoherentMap, test02) {
	collections::coherent_map<int, int> x;
	EXPECT_EQ(0, x[0]);
}

TEST(CoherentMap, test03) {
	collections::coherent_map<int, int> x;
	x[0] = 1337;
	EXPECT_EQ(1337, x[0]);
}

TEST(CoherentMap, test04) {
	collections::coherent_map<int, int> x;
	x[0] = 1337;
	x.erase(0);
	ASSERT_EQ(0, x.size());
}

TEST(CoherentMap, test05) {
	collections::coherent_map<int, std::string> x;
	for (auto i = 0; i < 1000000; ++i) {
		x[i] = std::to_string(i);
	}
	for (auto const & entry: x) {
		ASSERT_EQ(std::to_string(entry.first), entry.second);
	}
}

TEST(CoherentMap, test06) {
	collections::coherent_map<int, std::string> x;
	for (auto i = 0; i < 1000000; ++i) {
		x[i] = std::to_string(i);
	}
	for (auto i = 0; i < 1000000; ++i) {
		auto entry = *x.find(i);
		ASSERT_EQ(std::to_string(entry.first), entry.second);
	}
}

TEST(CoherentMap, test07) {
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
		auto result = x.insert(make_pair(j, std::to_string(j)));
		ASSERT_EQ(true, result.second);
	}

	for (auto i = 0; i < 10000; ++i) {
		auto entry = *x.find(i);
		ASSERT_EQ(std::to_string(entry.first), entry.second);
	}
}

TEST(CoherentMap, test08) {
	std::vector<std::pair<int, int>> data{std::make_pair(0, 1337)};
	collections::coherent_map<int, int> x;
	ASSERT_EQ(1, x.insert_many(data.begin(), data.end()));
	EXPECT_EQ(1337, x[0]);
}

TEST(CoherentMap, test09) {
	std::vector<std::pair<int, int>> data{std::make_pair(0, 0), std::make_pair(1, 1)};
	collections::coherent_map<int, int> x;
	ASSERT_EQ(2, x.insert_many(data.begin(), data.end()));
	EXPECT_EQ(0, x[0]);
	EXPECT_EQ(1, x[1]);
}

TEST(CoherentMap, test10) {
	std::vector<std::pair<int, int>> data{std::make_pair(1, 1), std::make_pair(0, 0)};
	collections::coherent_map<int, int> x;
	ASSERT_EQ(2, x.insert_many(data.begin(), data.end()));
	EXPECT_EQ(0, x[0]);
	EXPECT_EQ(1, x[1]);
}

TEST(CoherentMap, test11) {
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
		data.push_back(make_pair(j, std::to_string(j)));
	}

	collections::coherent_map<int, std::string> x;
	ASSERT_EQ(1000000, x.insert_many(data.begin(), data.end()));

	for (auto i = 0; i < 1000000; ++i) {
		auto entry = *x.find(i);
		ASSERT_EQ(std::to_string(entry.first), entry.second);
	}
}

TEST(CoherentMap, test12) {
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
		data.push_back(make_pair(j, std::to_string(j)));
	}

	collections::coherent_map<int, std::string> x;
	for (auto i = 0; i < 500; ++i) {
		auto j = data[i];
		x[j.first] = j.second;
	}

	ASSERT_EQ(999500, x.insert_many(data.begin(), data.end()));

	for (auto i = 0; i < 1000000; ++i) {
		auto entry = *x.find(i);
		ASSERT_EQ(std::to_string(entry.first), entry.second);
	}
}

TEST(CoherentMap, test13) {
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
		data.push_back(make_pair(j, std::to_string(j)));
	}

	collections::coherent_map<int, std::string> x;
	ASSERT_EQ(1000000, x.insert_many(data.begin(), data.end()));

	size_t counter = 0;
	for (auto const & entry: x) {
		ASSERT_EQ(counter++, entry.first);
	}
}

TEST(CoherentMap, test14) {
	collections::coherent_map<void const *, int> x;
	x[nullptr] = 1337;
	x.erase(nullptr);
	ASSERT_EQ(0, x.size());
}