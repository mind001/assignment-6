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

// alias std::pair<int,int> to be called Edge for readability
using Edge = std::pair<int, int>;

// An undirected graph backed by an adjacency list
class Graph {
private:
  std::set<int> vertices_;
  std::map<int, std::set<int>> adjacency_list_;

public:
  Graph() = default;
  Graph(std::set<int> vertices, std::set<Edge> edges);

  // return whether this graph cotains a cycle
  auto ContainsCycle() -> bool;
};
} // namespace assignment6
#endif // ASSIGNMENT_6_GRAPH_HPP
