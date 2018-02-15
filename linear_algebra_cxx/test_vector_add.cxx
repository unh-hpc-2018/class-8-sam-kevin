
#include "linear_algebra.hxx"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the vec_add() function

int
main(int argc, char **argv)
{
  struct vector *x = new vector(3, (double[3]) { 1., 2., 3. });
  struct vector *y = new vector(3, (double[3]) { 2., 3., 4. });
  struct vector *z = new vector(3);
  struct vector *z_ref = new vector(3, (double[3]) { 3., 5., 7. });

  vector_add(x, y, z);

  std::cout << "sum vector is z = " << z << std::endl;

  // check result agains reference result
  assert(z == z_ref);

  return 0;
}
