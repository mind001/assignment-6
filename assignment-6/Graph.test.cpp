#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"
#include "Graph.hpp"
#include "Graphs.hpp"

using namespace assignment6;

TEST_CASE("C4 is a cycle") {
    CHECK(C4.ContainsCycle());
}

TEST_CASE("G1 contains a cycle") {
    CHECK(G1.ContainsCycle());
}

TEST_CASE("G2 does not contain a cycle") {
    CHECK_FALSE(G2.ContainsCycle());
}
