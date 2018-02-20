
#include "linear_algebra.hxx"

// ----------------------------------------------------------------------
// matrix_matrix_mul
//
// performs the matrix-matrix multiplication C = A B
// A: 1st input matrix (m x k matrix)
// B: 2nd input matrix (k x n matrix)
// C: result (m x n matrix)

matrix operator*(const matrix& A, const matrix& B)
{
  matrix C(A.m, B.n);

  for (int i = 0; i < C.m; i++) {
    for (int j = 0; j < C.n; j++) {
      for (int k = 0; k < C.m; k++) {
	C(i, j) += A(i, k) * B(k, j);
      }
    }
  }
  return C;
}

