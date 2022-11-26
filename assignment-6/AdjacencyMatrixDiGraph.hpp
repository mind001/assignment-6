#ifndef ASSIGNMENT_6_ADJACENCYMATRIXDIGRAPH_HPP
#define ASSIGNMENT_6_ADJACENCYMATRIXDIGRAPH_HPP

#include "Graph.hpp"
#include <boost/numeric/ublas/matrix.hpp>
#include <set>

namespace assignment6 {

namespace bnu = boost::numeric::ublas;

// A directed graph backed by an adjacency matrix
class AdjacencyMatrixDiGraph {
private:
  // the set of vertices of the graph
  std::set<int> vertices_;
  // the adjacency matrix
  bnu::matrix<int> adjacency_matrix_;

public:
  AdjacencyMatrixDiGraph() = default;
  AdjacencyMatrixDiGraph(std::vector<int>, std::vector<Edge>);
  AdjacencyMatrixDiGraph(std::set<int>, std::set<Edge>);
  AdjacencyMatrixDiGraph(bnu::matrix<int>);

  // Check whether this is the same as another adjacency matrix digraph
  auto IsSame(AdjacencyMatrixDiGraph other) -> bool;

  // Return the transpose of this graph (i.e. the directed graph with the edges reversed)
  auto Transpose() -> AdjacencyMatrixDiGraph;
};
} // namespace assignment6
#endif // ASSIGNMENT_6_ADJACENCYMATRIXDIGRAPH_HPP
