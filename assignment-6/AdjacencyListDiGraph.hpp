#ifndef ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP
#define ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP

#include "Graph.hpp"
#include <boost/graph/adjacency_list.hpp>

namespace assignment6 {

class AdjacencyListDiGraph {
  boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, VertexInfo> g_;

public:
  AdjacencyListDiGraph() = default;
  AdjacencyListDiGraph(std::vector<int>, std::vector<Edge>);

  auto IsIsomorphic(AdjacencyListDiGraph &other) -> bool;

  auto Transpose() -> AdjacencyListDiGraph;
};

} // namespace assignment6

#endif // ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP
