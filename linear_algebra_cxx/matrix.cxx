
#include "linear_algebra.hxx"

#include <stdlib.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// matrix::constructor
//
// create a new matrix of size "m" x "n"

matrix::matrix(int _m, int _n)
  : m(_m), n(_n)
{
  vals = new double[m*n];
}

// ----------------------------------------------------------------------
// matrix::destructor
//
// destroys (deallocates) the matrix "M"

matrix::~matrix()
{
  delete[] vals;
}

// ----------------------------------------------------------------------
// matrix_print
//
// prints matrix "M" to stdout

void
matrix_print(struct matrix *M)
{
  printf("[(#=%dx%d)", M->m, M->n);
  for (int i = 0; i < M->m; i++) {
    printf(" {");
    for (int j = 0; j < M->n; j++) {
      printf(" %g", MAT(M, i, j));
    }
    printf(" }");
  }
  printf("]");
}
