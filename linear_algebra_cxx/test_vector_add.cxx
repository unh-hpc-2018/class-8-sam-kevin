
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
  vector x(3, (double[3]) { 1., 2., 3. });
  vector y(3, (double[3]) { 2., 3., 4. });
  vector z_ref(3, (double[3]) { 3., 5., 7. });

  vector z = x + y;

  std::cout << "sum vector is z = " << z << std::endl;

  // check result agains reference result
  assert(z == z_ref);

  return 0;
}
