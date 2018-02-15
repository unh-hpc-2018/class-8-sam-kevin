
#include "linear_algebra.hxx"

// ----------------------------------------------------------------------
// matrix_vector_mul
//
// calculate y = Ax,
// where x and y are vectors, and A is a matrix

void matrix_vector_mul(const matrix& A, const vector& x, vector& y)
{
  for (int i = 0; i < A.m; i++) {
    y[i] = 0.;
    for (int j = 0; j < A.n; j++) {
      y[i] += MAT(A, i, j) * x[j];
    }
  }
}
