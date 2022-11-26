#include <boost/numeric/ublas/matrix.hpp>

using namespace boost::numeric::ublas;

// Define equality for boost matrices for use in AdjacencyMatrixDiGraph::IsSame
// https://stackoverflow.com/a/3120784/424173
template <typename T>
auto operator==(const matrix<T> &m1, const matrix<T> &m2) -> bool {
  // first, check that they have the same dimensions
  bool returnValue = (m1.size1() == m2.size1() && m1.size2() == m2.size2());
  if (returnValue) {
    // now check each element, including returnValue in the condition of the loop
    // means we can terminate early if we find a mismatch
    for (auto i = 0; returnValue && i < m1.size1(); i++) {
      for (auto j = 0; returnValue && j < m1.size2(); j++) {
          returnValue &= m1(i,j) == m2(i,j);
      }
    }
  }
  return returnValue;
}
