#include "AdjacencyListDiGraph.hpp"
#include "Graph.hpp"
#include "boost/graph/isomorphism.hpp"
#include <stdexcept>

namespace assignment6 {

AdjacencyListDiGraph::AdjacencyListDiGraph(std::set<int> vertices,
                                           std::set<Edge> edges) {
  vertices_ = vertices;
  for (auto v : vertices) {
    adjacent_vertices_.emplace(v, std::set<int>{});
  }
  for (Edge e : edges) {
    adjacent_vertices_.at(e.first).insert(e.second);
  }
}

AdjacencyListDiGraph::AdjacencyListDiGraph(std::vector<int> vertices,
                                           std::vector<Edge> edges)
    : AdjacencyListDiGraph(std::set<int>(vertices.begin(), vertices.end()),
                           std::set<Edge>(edges.begin(), edges.end())) {}

auto AdjacencyListDiGraph::IsSame(AdjacencyListDiGraph other) -> bool {
  return vertices_ == other.vertices_ &&
         adjacent_vertices_ == other.adjacent_vertices_;
}

auto AdjacencyListDiGraph::Transpose() -> AdjacencyListDiGraph {
  throw std::runtime_error("Implement me!");
}
} // namespace assignment6
