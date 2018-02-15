
#include "linear_algebra.hxx"

#include <stdlib.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// vector::constructor
//
// construct a vector of length "n"

vector::vector(int _n)
{
  n = _n;
  vals = new double[n]{};
}


// ----------------------------------------------------------------------
// vector::constructor
//
// construct a vector of length "n" and set values

vector::vector(int _n, const double* vals)
  : vector(_n)
{
  for (int i = 0; i < n; i++) {
    VEC(this, i) = vals[i];
  }
}

// ----------------------------------------------------------------------
// vector::destructor
//
// construct a vector of length "n" and set values

vector::~vector()
{
  free(vals);
}

// ----------------------------------------------------------------------
// vector_create
//
// create a new vector of length "n"

struct vector *
vector_create(int n)
{
  return new vector(n);
}

// ----------------------------------------------------------------------
// vector_create_and_set
//
// create a new vector of length "n", and set the values from "vals"

struct vector *
vector_create_and_set(int n, const double *vals)
{
  return new vector(n, vals);
}

// ----------------------------------------------------------------------
// vector_destroy
//
// destroys (deallocates) the vector "v"

void
vector_destroy(struct vector *v)
{
  delete v;
}

// ----------------------------------------------------------------------
// vector_is_equal

bool
vector_is_equal(const struct vector *x, const struct vector *y)
{
  for (int i = 0; i < x->n; i++) {
    if (VEC(x, i) != VEC(y, i)) {
      return false;
    }
  }
  return true;
}

// vector_print
//
// prints vector "v" to stdout

void
vector_print(struct vector *v)
{
  printf("[(#=%d)", v->n);
  for (int i = 0; i < v->n; i++) {
    printf(" %g", VEC(v, i));
  }
  printf("]");
}

