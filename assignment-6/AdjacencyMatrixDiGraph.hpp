#ifndef ASSIGNMENT_6_ADJACENCYMATRIXDIGRAPH_HPP
#define ASSIGNMENT_6_ADJACENCYMATRIXDIGRAPH_HPP

#include <set>
#include <boost/numeric/ublas/matrix.hpp>
#include "Graph.hpp"

namespace assignment6 {

namespace bnu = boost::numeric::ublas;

class AdjacencyMatrixDiGraph {
private:
  std::set<int> vertices_;
  bnu::matrix<int> adjacency_matrix_;

public:
  AdjacencyMatrixDiGraph() = default;
  AdjacencyMatrixDiGraph(std::vector<int>, std::vector<Edge>);


  auto IsSame(AdjacencyMatrixDiGraph other) -> bool;

  auto Transpose() -> AdjacencyMatrixDiGraph;

};
} // namespace assignment6
#endif // ASSIGNMENT_6_ADJACENCYMATRIXDIGRAPH_HPP
