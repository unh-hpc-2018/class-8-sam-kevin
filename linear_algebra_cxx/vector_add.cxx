
#include "linear_algebra.hxx"

// ----------------------------------------------------------------------
// vector_add
//
// calculate z = x + y, for the vectors x, y, z

vector operator+(const vector& x, const vector& y)
{
  assert(x.n == y.n);
  vector z(x.n);
  for (int i = 0; i < x.n; i++) {
    z[i] = x[i] + y[i];
  }

  return z;
}
