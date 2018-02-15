
#include "linear_algebra.hxx"

#include <algorithm>
#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// setup_test_matrices
//
// initializes the two matrices A, B, and the reference solution C_ref

static void
setup_test_matrices(matrix& A, matrix& B, matrix& C_ref)
{
  // the test matrices are diagonal, which isn't really good,
  // a more general test case would be better.

  // the matrices are initialized to zero, so we only set the non-zero elements
  // on the diagonal
  for (int i = 0; i < std::min(A.m, A.n); i++) {
    A(i, i) = i;
  }
  for (int i = 0; i < std::min(B.m, B.n); i++) {
    B(i, i) = i;
  }
  for (int i = 0; i < std::min({C_ref.m, C_ref.n, A.n}); i++) {
    C_ref(i, i) = i * i;
  }
}

// ----------------------------------------------------------------------
// main
//
// test the mat_vec_mul() function

int
main(int argc, char **argv)
{
  const int m = 500, n = 500, k = 200;

  matrix A(m, k);
  matrix B(k, n);
  matrix C(m, n);
  matrix C_ref(m, n);

  // build a test matrix
  setup_test_matrices(A, B, C_ref);

  // calculate C = AB
  matrix_matrix_mul(A, B, C);

  /* printf("C = "); */
  /* matrix_print(C); */
  /* printf("\n"); */

  // the resulting vector for this test should equal our reference result
  // FIXME, operator== is missing
  // assert(C ==  C_ref);

  return 0;
}

