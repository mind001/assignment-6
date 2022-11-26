#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"
#include "AdjacencyListDiGraph.hpp"
#include "Graphs.hpp"

using namespace assignment6;


TEST_CASE("Test transpose: CLAW") {

  AdjacencyListDiGraph result = CLAW_LIST.Transpose();

  CHECK(TRANSPOSE_CLAW_LIST.IsSame(result));
}

TEST_CASE("Test transpose : D1") {
  AdjacencyListDiGraph result = D1_LIST.Transpose();
  CHECK(D1_TRANSPOSE_LIST.IsSame(result));
}

TEST_CASE("Test transpose : D2") {
  AdjacencyListDiGraph result = D2_LIST.Transpose();
  CHECK(D2_TRANSPOSE_LIST.IsSame(result));
}
