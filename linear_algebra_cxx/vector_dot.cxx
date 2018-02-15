
#include "linear_algebra.hxx"

#define N (3)

// ----------------------------------------------------------------------
// vector_dot
//
// returns the dot product of the two vectors
// x: first vector
// y: second vector

double dot(const struct vector& x, const struct vector& y)
{
  double sum = 0.;
  for (int i = 0; i < x.n; i++) {
    sum += x[i] * y[i];
  }
  return sum;
}

