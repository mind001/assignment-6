#ifndef ASSIGNMENT_6_GRAPH_HPP
#define ASSIGNMENT_6_GRAPH_HPP

#include <utility>
#include <vector>

namespace assignment6 {

using Edge = std::pair<int, int>;

struct Vertex {
  int id;
};

class Graph {
public:
  Graph() = default;
  Graph(std::vector<int> vertices, std::vector<Edge> edges);

  auto ContainsCycle() -> bool;
};
}
#endif // ASSIGNMENT_6_GRAPH_HPP
