#include "../tarjan.hpp"

#include "gtest/gtest.h"

TEST(Tarjan, verts_0_edges_0) {
	std::vector<std::string> vertices;
	std::vector<std::vector<size_t>> expected{};
	auto const actual = tarjan(0, [](size_t const &) { return std::vector<size_t>(); });
	ASSERT_EQ(expected, actual);
}

TEST(Tarjan, verts_2_edges_1) {
	std::vector<std::string> vertices;
	vertices.emplace_back("0");
	vertices.emplace_back("1");
	std::vector<std::vector<size_t>> expected{{1}, {0}};
	auto const actual = tarjan(vertices.size(), [&](size_t i)
	{
		if (i == 0) {
			return std::vector<size_t>{1};
		}
		return std::vector<size_t>{};
	});
	ASSERT_EQ(expected.size(), actual.size());
	for (size_t i = 0; i < expected.size(); ++i) {
		auto const & subExpected = expected[i];
		auto const & subActual = actual[i];
		ASSERT_EQ(subExpected.size(), subActual.size());
		for (size_t j = 0; j < subExpected.size(); ++j) {
			ASSERT_EQ(subExpected[j], subActual[j]);
		}
	}
	EXPECT_EQ(expected, actual);
}

TEST(Tarjan, strongly_connected_verts_2_edges_2) {
	std::vector<std::string> vertices;
	vertices.emplace_back("0");
	vertices.emplace_back("1");
	std::vector<std::vector<size_t>> expected{{1, 0}};
	auto const actual = tarjan(vertices.size(), [&](size_t i)
		{
			if (i == 0) {
				return std::vector<size_t>{1};
			} else {
				return std::vector<size_t>{0};
			}
			return std::vector<size_t>{};
		});
	ASSERT_EQ(expected.size(), actual.size());
	for (size_t i = 0; i < expected.size(); ++i) {
		auto const & subExpected = expected[i];
		auto const & subActual = actual[i];
		ASSERT_EQ(subExpected.size(), subActual.size());
		for (size_t j = 0; j < subExpected.size(); ++j) {
			ASSERT_EQ(subExpected[j], subActual[j]);
		}
	}
	EXPECT_EQ(expected, actual);
}

