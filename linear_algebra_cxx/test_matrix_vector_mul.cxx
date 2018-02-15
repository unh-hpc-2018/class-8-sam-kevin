
#include "linear_algebra.hxx"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the matrix_vector_mul() function

int
main(int argc, char **argv)
{
  struct matrix *A = matrix_create(3, 3);
  for (int i = 0; i < 3; i++) {
    MAT(A, i, i) = i + 1;
  }
  vector x(3, (double[3]) { 1., 2., 3. });
  vector y(3);
  vector y_ref(3, (double[3]) { 1., 4., 9. });

  matrix_print(A);
  printf("\n");
  
  matrix_vector_mul(A, &x, &y);

  std::cout << "result vector is y = " << y << std::endl;

  // check result against reference result
  assert(y == y_ref);

  return 0;
}
