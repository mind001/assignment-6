cmake_minimum_required(VERSION 3.14)

project("Assignment 6")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # generate compile_commands.json for IDEs
set(CMAKE_CXX_STANDARD 17)

# Setting -ggdb3 gets line numbers in Valgrind output -Og is the recommended
# level of optimization from the GCC docs for "the standard edit-compile-debug"
# cycle https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3 -Og")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake) # make sure we know
                                                         # where to find the
                                                         # doctest header

find_package(Doctest REQUIRED)

include(cmake/ClangFormat.cmake)
include(cmake/ClangTidy.cmake)
include(cmake/Valgrind.cmake)

# Attempt to fix the icu issues on OS X. If this doesn't work, let me know
if(APPLE OR (CMAKE_SYSTEM_NAME EQUAL "Darwin"))
  # prefer homebrew-install icu4c since the default seems not to be working
  set(CMAKE_PREFIX_PATH "/opt/hombrew/opt/icu4c")

  list(TRANSFORM CMAKE_PREFIX_PATH
       APPEND "/include" OUTPUT_VARIABLE CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES)
  set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES
      "${CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES}")
endif()

find_package(Boost)
if(NOT Boost_FOUND)
  message(STATUS "Boost not found. Downloading.")
  include(FetchContent)
  FetchContent_Declare(
    boost
    GIT_REPOSITORY https://github.com/boostorg/boost.git
    GIT_TAG boost-1.80.0
    GIT_SHALLOW true)

  FetchContent_MakeAvailable(boost)
else()
  include_directories(${Boost_INCLUDE_DIRS})
endif()

# Use include(CTest) rather than enable_testing() to get Valgrind working
include(CTest)

add_library(
  Graph
  assignment-6/Graph.hpp
  assignment-6/Graph.cpp
  assignment-6/Matrix.hpp
  assignment-6/AdjacencyListDiGraph.hpp
  assignment-6/AdjacencyListDiGraph.cpp
  assignment-6/AdjacencyMatrixDiGraph.cpp
  assignment-6/AdjacencyMatrixDiGraph.hpp)

add_executable(GraphTest assignment-6/AdjacencyListDiGraph.test.cpp)
target_link_libraries(GraphTest Doctest Graph)

add_test(GraphTest GraphTest)

