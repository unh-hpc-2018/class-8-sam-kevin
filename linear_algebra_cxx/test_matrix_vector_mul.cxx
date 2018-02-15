
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
  matrix A(3, 3);
  for (int i = 0; i < 3; i++) {
    MAT(A, i, i) = i + 1;
  }
  vector x{ 1., 2., 3. };
  vector y(3);

  matrix_print(A);
  printf("\n");
  
  matrix_vector_mul(A, x, y);

  std::cout << "result vector is y = " << y << std::endl;

  // check result against reference result
  assert((y == vector{ 1., 4., 9. }));

  return 0;
}
