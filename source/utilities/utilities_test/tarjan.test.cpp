#include "gtest/gtest.h"

#include "../tarjan.hpp"

TEST(Tarjan, instantiate_template) {	
	struct functor {
		std::vector<size_t *> operator()(size_t * const & i) const { return {}; }
	};
	(void)&tarjan<size_t, functor>;
}

TEST(Tarjan, verts_0_edges_0) {
	std::vector<size_t> vertices;
	typedef std::vector<size_t>::iterator iterator;
	std::vector<std::vector<iterator>> expected{};
	auto const actual = tarjan<iterator>(vertices.begin(), vertices.end(), [](iterator const &) { return std::vector<iterator>(); });
	ASSERT_EQ(expected, actual);
}

TEST(Tarjan, verts_2_edges_1) {
	std::vector<size_t> vertices;
	vertices.push_back(0);
	vertices.push_back(1);
	typedef std::vector<size_t>::iterator iterator;
	std::vector<std::vector<iterator>> expected{{vertices.begin() + 1}, {vertices.begin() + 0}};
	auto const actual = tarjan<iterator>(vertices.begin(), vertices.end(), [&](iterator const & i)
	{
		if (i == vertices.begin()) {
			return std::vector<iterator>{vertices.begin() + 1};
		}
		return std::vector<iterator>{};
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
	std::vector<size_t> vertices;
	vertices.push_back(0);
	vertices.push_back(0);
	typedef std::vector<size_t>::iterator iterator;
	std::vector<std::vector<iterator>> expected{{vertices.begin() + 1, vertices.begin() + 0}};
	auto const actual = tarjan<iterator>(vertices.begin(), vertices.end(), [&](iterator const & i){
		if (i == vertices.begin()) {
			return std::vector<iterator>{vertices.begin() + 1};
		} else {
			return std::vector<iterator>{vertices.begin()};
		}
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

TEST(Tarjan, ptr_verts) {
	struct functor {
		std::vector<size_t **> operator()(size_t ** const & i) const { return {}; }
	};
	(void)&tarjan<size_t *, functor>;
}