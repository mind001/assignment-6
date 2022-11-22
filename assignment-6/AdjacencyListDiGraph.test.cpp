#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"
#include "AdjacencyListDiGraph.hpp"

using namespace assignment6;

auto Claw() -> AdjacencyListDiGraph {
  std::vector<int> vertices {0,1,2,3};
  std::vector<Edge> edges {Edge(0,1), Edge(0,2), Edge(0,3)};

  return AdjacencyListDiGraph(vertices, edges); // NOLINT
}

TEST_CASE("Test construction of adjacency digraph") {
  std::vector<int> vertices {0,1,2,3};
  std::vector<Edge> edges {Edge(0,1), Edge(0,2)};

  AdjacencyListDiGraph G = AdjacencyListDiGraph(vertices, edges);
}

TEST_CASE("Test transpose") {
  AdjacencyListDiGraph G = Claw();
  std::vector<int> vertices {0,1,2,3};
  std::vector<Edge> edges {Edge(1,0), Edge(2,0), Edge(3,0)};
}