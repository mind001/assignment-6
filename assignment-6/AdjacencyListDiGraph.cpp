#include "AdjacencyListDiGraph.hpp"
#include "boost/graph/isomorphism.hpp"

namespace assignment6 {
AdjacencyListDiGraph::AdjacencyListDiGraph(std::vector<int> vertices, std::vector<Edge> edges) {
  for (int v : vertices) {
    boost::add_vertex(Vertex{v}, g_);
  }
  for (Edge e : edges) {
    boost::add_edge(e.first, e.second, g_);
  }
}

auto AdjacencyListDiGraph::Transpose() -> AdjacencyListDiGraph {
  throw std::runtime_error("Implement me!");
}

auto AdjacencyListDiGraph::IsIsomorphic(AdjacencyListDiGraph &other) -> bool {
  bool ret = true;
  // check that we have the same vertices


  // TODO: Fix this to actually check isomorphism using boost
  /**
#if defined(BOOST_MSVC) && BOOST_MSVC <= 1300
  bool ret = boost::isomorphism
      (g1, g2, make_iterator_property_map(f.begin(), v1_index_map, f[0]),
       boost::degree_vertex_invariant(), get(vertex_index, g1), get(vertex_index, g2));
#else
  bool ret = boost::isomorphism(this, other, isomorphism_map
       (boost::make_iterator_property_map(f.begin(), v1_index_map, f[0])));
#endif
   **/
  return ret;
}
} // namespace assignment6