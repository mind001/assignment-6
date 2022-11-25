#ifndef ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP
#define ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP

#include "Graph.hpp"
#include <boost/graph/adjacency_list.hpp>

namespace assignment6 {

using ALDG = boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::property<boost::vertex_name_t, int>>;

class AdjacencyListDiGraph {
  ALDG g_;

public:
  AdjacencyListDiGraph() = default;
  AdjacencyListDiGraph(std::vector<int>, std::vector<Edge>);

  auto IsSame(AdjacencyListDiGraph other) -> bool;

  auto Transpose() -> AdjacencyListDiGraph;
};

} // namespace assignment6

#endif // ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP
