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

class Graph {
private:
  std::set<int> vertices_;
  std::map<int, std::set<int>> adjacency_list_;

public:
  Graph() = default;
  Graph(std::vector<int> vertices, std::vector<Edge> edges);

  auto ContainsCycle() -> bool;
};
} // namespace assignment6
#endif // ASSIGNMENT_6_GRAPH_HPP
