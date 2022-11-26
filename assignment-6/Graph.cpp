#include "Graph.hpp"

#include <stack>
#include <stdexcept>

namespace std {
auto operator<<(ostream &os, const std::set<int> &s) -> ostream & {
  for (auto e : s) {
    os << e << ",";
  }
  return os;
}
auto operator<<(ostream &os, const std::map<int, std::set<int>> &m)
    -> ostream & {
  for (auto [k, v] : m) {
    os << k << ": " << v << std::endl;
  }
  return os;
}

auto operator<<(ostream &os, const assignment6::Edge &edge) -> ostream & {
  os << "(" << edge.first << "," << edge.second << ")";
  return os;
}
} // namespace std

namespace assignment6 {
Graph::Graph(std::set<int> vertices, std::set<Edge> edges) {
  vertices_ = vertices;
  for (const auto &v : vertices) {
    adjacency_list_.emplace(v, std::set<int>{});
  }
  for (const auto &e : edges) {
    adjacency_list_.at(e.first).insert(e.second);
    adjacency_list_.at(e.second).insert(e.first);
  }
}

auto Graph::ContainsCycle() -> bool {
  throw std::runtime_error("Implement me!");
}
} // namespace assignment6
