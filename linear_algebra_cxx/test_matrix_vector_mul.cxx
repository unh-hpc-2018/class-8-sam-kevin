
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
  struct vector *x = new vector(3, (double[3]) { 1., 2., 3. });
  struct vector *y = new vector(3);
  struct vector *y_ref = new vector(3, (double[3]) { 1., 4., 9. });

  matrix_print(A);
  printf("\n");
  
  matrix_vector_mul(A, x, y);

  printf("result vector is y = ");
  vector_print(y);
  printf("\n");

  // check result against reference result
  assert(vector_is_equal(y, y_ref));

  return 0;
}
