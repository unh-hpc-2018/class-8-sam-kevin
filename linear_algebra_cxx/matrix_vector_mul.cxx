
#include "linear_algebra.hxx"

// ----------------------------------------------------------------------
// operator*: perform matrix vector multiplication
//
// calculate y = Ax,
// where x and y are vectors, and A is a matrix

vector operator*(const matrix& A, const vector& x)
{
  vector y(x.size());

  for (int i = 0; i < A.m; i++) {
    for (int j = 0; j < A.n; j++) {
      y[i] += A(i, j) * x[j];
    }
  }

  return y;
}
