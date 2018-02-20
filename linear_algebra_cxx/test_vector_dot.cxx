
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
  vector x{ 1., 2., 3. };
  vector y{ 2., 3., 4. };

  printf("dot product is %g\n", dot(x, y));
  assert(dot(x, y) == 20.);

  return 0;
}
