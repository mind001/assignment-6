# Assignment 6

## 22.1-3: Transpose a Graph

The _transpose_ of a directed graph G=(V,E) is the graph G^T = (V, E^T) where E^T = {(v,u) | (u,v) in E } (i.e. the graph
with all the edges of G) reversed.

Implement `AdjacencyListDiGraph::Transpose` (in `AdjacencyListDiGraph.cpp`) and `AdjacencyMatrixDiGraph::Transpose`
(in `AdjacencyMatrixDiGraph.cpp`).

## 22.4-3: Cycle detection

Give an _undirected_ graph G, determine whether it contains a cycle.

Implement `Graph::ContainsCycle` in `Graph.cpp`

## Hints/Notes

- I wanted to use the Boost graph library, but in the interests of getting the assignment out, wrote my own quick and dirty implementations. One shortcoming is that this implementation assumes your vertices are called `0,1,2,...,n`. This is fine for purposes of the assignment, but you wouldn't want to assume that for a "real" implementation.
- How to check if a `std::set` contains an element? `visited.count(v) == 0` means `v` is *not* in the set `visited`.
- If you use `std::stack`, remember that popping the top element off the stack actually requires two lines:
```cpp
auto t = stack.top() // get the top element
stack.pop() // actually remove it from the stack (this function is a void)
```
- `AdjacencyMatrixDiGraph` uses the [Boost matrix library](https://www.boost.org/doc/libs/1_80_0/libs/numeric/ublas/doc/matrix.html) to represent the adjacency matrix. You basically
need to know two things:
    - To create a matrix `m` of size (say) 2x2: `bnu::matrix<int> m(2,2)` (see the constructor of `AdjacencyMatrixDiGraph`)
    - To access the element in the i-th row and j-th column of a matrix `m`, one writes `m(i,j)`.
