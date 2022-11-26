#include "AdjacencyMatrixDiGraph.hpp"
#include "Graph.hpp"
#include "Matrix.hpp"
#include <boost/numeric/ublas/matrix_expression.hpp>
#include <set>
#include <vector>

namespace assignment6 {

AdjacencyMatrixDiGraph::AdjacencyMatrixDiGraph(std::set<int> vertices,
                                               std::set<Edge> edges) {
  vertices_ = vertices;
  adjacency_matrix_ = bnu::matrix<int>(vertices.size(), vertices.size());
  // make sure we zero out the adjacency matrix -- is there a better way to do
  // this?
  for (auto i = 0; i < vertices.size(); i++) {
    for (auto j = 0; j < vertices.size(); j++) {
      adjacency_matrix_(i, j) = 0;
    }
  }
  for (auto &e : edges) {
    adjacency_matrix_(e.first, e.second) = 1;
    adjacency_matrix_(e.second, e.first) = -1;
  }
}

// This is an example of a "delegating constructor". We convert the arguments to
// sets and call the constructor that expects sets.
AdjacencyMatrixDiGraph::AdjacencyMatrixDiGraph(std::vector<int> vertices,
                                               std::vector<Edge> edges)
    : AdjacencyMatrixDiGraph(std::set<int>(vertices.begin(), vertices.end()),
                             std::set<Edge>(edges.begin(), edges.end())) {}

AdjacencyMatrixDiGraph::AdjacencyMatrixDiGraph(
    bnu::matrix<int> adjacency_matrix) {
  adjacency_matrix_ = adjacency_matrix;
  // we know what the vertices are -- they're the same as the indices of the
  // rows/columns of the adjacency matrix
  for (auto i = 0; i < adjacency_matrix.size1(); i++) {
    vertices_.insert(i);
  }
}

auto AdjacencyMatrixDiGraph::IsSame(AdjacencyMatrixDiGraph other) -> bool {
  return vertices_ == other.vertices_ &&
         adjacency_matrix_ == other.adjacency_matrix_;
}

auto AdjacencyMatrixDiGraph::Transpose() -> AdjacencyMatrixDiGraph {
    throw std::runtime_error("Implement me!");
}
} // namespace assignment6
