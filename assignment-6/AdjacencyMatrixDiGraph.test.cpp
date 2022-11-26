#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "Graphs.hpp"
#include "doctest/doctest.h"

TEST_CASE("Test IsSame") { CHECK(CLAW_MATRIX.IsSame(CLAW_MATRIX)); }

TEST_CASE("Test transpose") {
  CHECK(TRANSPOSE_CLAW_MATRIX.IsSame(CLAW_MATRIX.Transpose()));
}
