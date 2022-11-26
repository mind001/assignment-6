#ifndef ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP
#define ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP

#include "Graph.hpp"
#include <boost/graph/adjacency_list.hpp>

namespace assignment6 {

// Directed graph implemented via an adjacency list
class AdjacencyListDiGraph {
private:
    // the vertices of the graph
  std::set<int> vertices_;
  // a map whose keys are vertices and whose values are the vertices adjacent to the key
  // for example if the key is v then a value of {w1, w2} would mean the graph contains
  // (directed) edges v -> w1 and v -> w2 (and no other edges originating from v)
  std::map<int, std::set<int>> adjacent_vertices_;

public:
  AdjacencyListDiGraph() = default;
  AdjacencyListDiGraph(std::set<int>, std::set<Edge>);
  AdjacencyListDiGraph(std::vector<int>, std::vector<Edge>);

  // Check whether this is the same as another adjacency list digraph
  auto IsSame(AdjacencyListDiGraph other) -> bool;

  // Return the Transpose of this graph, i.e. the graph whose edges all point the
  // opposite direction
  auto Transpose() -> AdjacencyListDiGraph;
};

} // namespace assignment6

#endif // ASSIGNMENT_6_ADJACENCYLISTDIGRAPH_HPP
