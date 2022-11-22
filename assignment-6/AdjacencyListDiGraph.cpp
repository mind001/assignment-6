#include "AdjacencyListDiGraph.hpp"

namespace assignment6 {
AdjacencyListDiGraph::AdjacencyListDiGraph(std::vector<int> vertices, std::vector<Edge> edges) {
  size_t num_edges = edges.size();
  for (int v : vertices) {
    boost::add_vertex(VertexInfo{v}, g_);
  }
  for (Edge e : edges) {
    boost::add_edge(e.first, e.second, g_);
  }
}

auto AdjacencyListDiGraph::Transpose() -> AdjacencyListDiGraph {
  throw std::runtime_error("Implement me!");
}

auto AdjacencyListDiGraph::IsIsomorphic(AdjacencyListDiGraph &other) -> bool {

}
} // namespace assignment6