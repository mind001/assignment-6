#include "Graph.hpp"

#include <stdexcept>

namespace assignment6 {
Graph::Graph(std::vector<int> vertices, std::vector<Edge> edges) {
  vertices_ = std::set<int>(vertices.begin(), vertices.end());
  for (const auto &v : vertices) {
    adjacency_list_.at(v) = std::set<int>{};
  }
  for (const auto &e : edges) {
    adjacency_list_.at(e.first).insert(e.second);
    adjacency_list_.at(e.second).insert(e.first);
  }
}

auto Graph::ContainsCycle() -> bool {
  throw std::runtime_error("Implement me");
}
} // namespace assignment6
