#ifndef ASSIGNMENT_6_GRAPH_HPP
#define ASSIGNMENT_6_GRAPH_HPP

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/isomorphism.hpp>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

namespace assignment6 {

using Edge = std::pair<int, int>;

struct Vertex {
  int id;
};

template <class graph> struct vertex_invariant {
  using Map = std::map<int, size_t>;
  using argument_type = typename boost::graph_traits<graph>::vertex_descriptor;

  const graph &m_graph;
  Map mappings;

  auto operator()(argument_type u) const -> size_t {
    return mappings.at(boost::get(boost::vertex_name, m_graph, u));
  }

  [[nodiscard]] auto max() const noexcept -> size_t { return mappings.size(); }

  void collect_names() noexcept {
    for (auto vd : boost::make_iterator_range(boost::vertices(m_graph))) {
      size_t next_id = mappings.size();
      auto ins = mappings.insert(
          {boost::get(boost::vertex_name, m_graph, vd), next_id});
      if (ins.second) {
        std::cout << "Mapped " << ins.first->first << " to "
                  << ins.first->second << std::endl;
      }
    }
  }
};
;

// https://stackoverflow.com/a/34520444/424173
template <typename graph>
auto is_same_graph(const graph &g1, const graph &g2) noexcept -> bool {
  auto ref_index_map = get(boost::vertex_index, g1);
  using vd = typename boost::graph_traits<graph>::vertex_descriptor;
  std::vector<vd> iso(boost::num_vertices(g1));

  typename vertex_invariant<graph>::Map shared_names;
  vertex_invariant<graph> inv1{g1, shared_names};
  vertex_invariant<graph> inv2{g1, shared_names};
  inv1.collect_names();
  inv2.collect_names();

  return boost::isomorphism(
      g1, g2,
      boost::isomorphism_map(
          boost::make_iterator_property_map(iso.begin(), ref_index_map))
          .template vertex_invariant1(inv1)
          .template vertex_invariant2(inv2));
}

template <typename graph> class BaseGraph {
protected:
  graph g_;

public:
  auto IsSame(BaseGraph<graph> other) -> bool {
    return is_same_graph(g_, other.g_);
  }
};

class Graph {
public:
  Graph() = default;
  Graph(std::vector<int> vertices, std::vector<Edge> edges);

  auto ContainsCycle() -> bool;
};
} // namespace assignment6
#endif // ASSIGNMENT_6_GRAPH_HPP
