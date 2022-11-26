#ifndef ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP
#define ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP

#include "Graph.hpp"
#include <boost/graph/adjacency_list.hpp>

namespace assignment6 {

class AdjacencyListDiGraph {
private:
  std::set<int> vertices_;
  std::map<int, std::set<int>> adjacent_vertices_;
public:
  AdjacencyListDiGraph() = default;
  AdjacencyListDiGraph(std::vector<int>, std::vector<Edge>);

  auto IsSame(AdjacencyListDiGraph other) -> bool;

  auto Transpose() -> AdjacencyListDiGraph;
};

} // namespace assignment6

#endif // ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP
