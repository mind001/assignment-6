#include "AdjacencyListDiGraph.hpp"
#include "boost/graph/isomorphism.hpp"
#include "Graph.hpp"

namespace assignment6 {

AdjacencyListDiGraph::AdjacencyListDiGraph(std::vector<int> vertices,
                                           std::vector<Edge> edges) {
  for (auto v : vertices) {
    vertices_.insert(v);
    adjacent_vertices_.emplace(v, std::set<int>{});
  }

  for (Edge e : edges) {
    adjacent_vertices_.at(e.first).insert(e.second);
  }
}

auto AdjacencyListDiGraph::IsSame(AdjacencyListDiGraph other) -> bool {
  return vertices_ == other.vertices_ && adjacent_vertices_ == other.adjacent_vertices_;
}

auto AdjacencyListDiGraph::Transpose() -> AdjacencyListDiGraph {
  throw std::runtime_error("Implement me!");
}
} // namespace assignment6