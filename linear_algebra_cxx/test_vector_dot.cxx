
#include "linear_algebra.hxx"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_dot() function

int
main(int argc, char **argv)
{
  struct vector *x = new vector(3, (double[3]) { 1., 2., 3. });
  struct vector *y = new vector(3, (double[3]) { 2., 3., 4. });

  printf("dot product is %g\n", vector_dot(x, y));
  assert(vector_dot(x, y) == 20.);

  delete x;
  delete y;

  return 0;
}
