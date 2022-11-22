#include "Graph.hpp"

#include <stdexcept>

namespace assignment6 {
Graph::Graph(std::vector<int> vertices, std::vector<Edge> edges) {

}

auto Graph::ContainsCycle() -> bool { throw std::runtime_error("Implement me"); }
}