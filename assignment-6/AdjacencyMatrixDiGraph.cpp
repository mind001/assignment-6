#include "AdjacencyMatrixDiGraph.hpp"
#include "Graph.hpp"
#include "Matrix.hpp"
#include <set>
#include <vector>

namespace assignment6 {
AdjacencyMatrixDiGraph::AdjacencyMatrixDiGraph(std::vector<int> vertices,
                                               std::vector<Edge> edges) {
  vertices_ = std::set<int>{};
  adjacency_matrix_ = bnu::matrix<int>(vertices.size(), vertices.size());
  for (auto &v : vertices) {
    vertices_.insert(v);
  }
  for (auto &e : edges) {
    adjacency_matrix_(e.first, e.second) = 1;
    adjacency_matrix_(e.second, e.first) = -1;
  }
}

auto AdjacencyMatrixDiGraph::IsSame(AdjacencyMatrixDiGraph other) -> bool{
    return vertices_ == other.vertices_ && adjacency_matrix_ == other.adjacency_matrix_;
}
} // namespace assignment6
