#include "AdjacencyListDiGraph.hpp"
#include "boost/graph/isomorphism.hpp"
#include <iostream>
#include "Graph.hpp"

namespace assignment6 {

AdjacencyListDiGraph::AdjacencyListDiGraph(std::vector<int> vertices,
                                           std::vector<Edge> edges) {
  for (Edge e : edges) {
    boost::add_edge(e.first, e.second, g_);
  }
}



auto AdjacencyListDiGraph::Transpose() -> AdjacencyListDiGraph {
  throw std::runtime_error("Implement me!");
}
auto AdjacencyListDiGraph::IsSame(AdjacencyListDiGraph other) -> bool {
  return is_same_graph(g_, other.g_);
}
} // namespace assignment6