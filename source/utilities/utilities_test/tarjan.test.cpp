#include "gtest/gtest.h"

#include "../tarjan.hpp"

TEST(Tarjan, instantiate_template) {
	typedef std::vector<std::string>::iterator iterator_t;
	struct functor {
		std::vector<iterator_t> operator()(iterator_t const & i) const { return {}; }
	};
	(void)&tarjan<iterator_t, functor>;
}

TEST(Tarjan, verts_0_edges_0) {
	std::vector<std::string> vertices;
	typedef std::vector<std::string>::iterator iterator;
	std::vector<std::vector<iterator>> expected{};
	auto const actual = tarjan<iterator>(vertices.begin(), vertices.end(), [](iterator const &) { return std::vector<iterator>(); });
	ASSERT_EQ(expected, actual);
}

TEST(Tarjan, verts_2_edges_1) {
	std::vector<std::string> vertices;
	vertices.emplace_back("0");
	vertices.emplace_back("1");
	typedef std::vector<std::string>::iterator iterator;
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
	std::vector<std::string> vertices;
	vertices.push_back(0);
	vertices.push_back(0);
	typedef std::vector<std::string>::iterator iterator;
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
	std::string vertices[2];
	vertices[0] = "0";
	vertices[1] = "1";
	struct functor {
		std::vector<std::string *> operator()(std::string * const & i) const { return {}; }
	};
	(void)tarjan<std::string *, functor>(vertices + 0, vertices + 1, functor());
}
