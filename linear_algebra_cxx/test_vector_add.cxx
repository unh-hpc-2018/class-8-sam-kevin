
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
  vector x{ 1., 2., 3. };
  vector y{ 2., 3., 4. };

  vector z = x + y;

  std::cout << "sum vector is z = " << z << std::endl;

  // check result against reference result
  assert((z == vector{ 3., 5., 7. }));

  return 0;
}
