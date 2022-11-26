#include "AdjacencyListDiGraph.hpp"
#include "AdjacencyMatrixDiGraph.hpp"
#include "Graph.hpp"

using namespace assignment6;

// This file just defines some graphs that are used in the tests

std::set<int> CLAW_VERTICES = {0, 1, 2, 3};
std::set<Edge> CLAW_EDGES = {Edge(0, 1), Edge(0, 2), Edge(0, 3)};
std::set<Edge> CLAW_TRANSPOSE_EDGES = {Edge(1, 0), Edge(2, 0), Edge(3, 0)};

std::set<Edge> D1_EDGES = {Edge(0,1), Edge(1,2), Edge(3,3)};
std::set<Edge> D1_TRANSPOSE_EDGES = {Edge(1,0), Edge(2,1), Edge(3,3)};

std::set<Edge> D2_EDGES = {Edge(0,1), Edge(1,3)};
std::set<Edge> D2_TRANSPOSE_EDGES = {Edge(1,0), Edge(3,1)};

auto CLAW_LIST = AdjacencyListDiGraph(CLAW_VERTICES, CLAW_EDGES);
auto CLAW_MATRIX = AdjacencyMatrixDiGraph(CLAW_VERTICES, CLAW_EDGES);

auto TRANSPOSE_CLAW_LIST =
    AdjacencyListDiGraph(CLAW_VERTICES, CLAW_TRANSPOSE_EDGES);
auto TRANSPOSE_CLAW_MATRIX =
    AdjacencyMatrixDiGraph(CLAW_VERTICES, CLAW_TRANSPOSE_EDGES);


auto C4 = Graph(std::set<int>{0, 1, 2, 3},
                std::set<Edge>{Edge(0, 1), Edge(1, 2), Edge(2, 3), Edge(3, 0)});

auto G1 = Graph(std::set<int>{0,1,2,3,4,5,6},
        std::set<Edge>{Edge(0,1), Edge(0,2), Edge(3,4), Edge(4,5), Edge(5,6), Edge(6,3)});

auto G2 = Graph(std::set<int>{0,1,2,3,4,5},
        std::set<Edge>{Edge(0,1), Edge(1,3), Edge(1,2), Edge(3,4), Edge(3,5)});

auto D1_LIST = AdjacencyListDiGraph(CLAW_VERTICES, D1_EDGES);
auto D1_TRANSPOSE_LIST = AdjacencyListDiGraph(CLAW_VERTICES, D1_TRANSPOSE_EDGES);

auto D2_LIST = AdjacencyListDiGraph(CLAW_VERTICES, D2_EDGES);
auto D2_TRANSPOSE_LIST = AdjacencyListDiGraph(CLAW_VERTICES, D2_TRANSPOSE_EDGES);

auto D1_MATRIX = AdjacencyMatrixDiGraph(CLAW_VERTICES, D1_EDGES);
auto D1_TRANSPOSE_MATRIX = AdjacencyMatrixDiGraph(CLAW_VERTICES, D1_TRANSPOSE_EDGES);

auto D2_MATRIX = AdjacencyMatrixDiGraph(CLAW_VERTICES, D2_EDGES);
auto D2_TRANSPOSE_MATRIX = AdjacencyMatrixDiGraph(CLAW_VERTICES, D2_TRANSPOSE_EDGES);
