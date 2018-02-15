
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <iostream>
#include <initializer_list>

#include <assert.h>

//#define BOUNDS_CHECK

// ----------------------------------------------------------------------
// struct vector

class vector
{
public:
  vector(int n);
  vector(int n, const double* vals);
  vector(std::initializer_list<double> l);
  ~vector();

  bool operator==(const vector& other) const;

  double  operator[](int i) const;
  double& operator[](int i);

  int size() const;

private:
  int check_index(int i) const;
  
  double *vals_;
  int n_;
};

std::ostream& operator<<(std::ostream& os, const vector& v);

double dot(const vector& x, const vector& y);
vector operator+(const vector& x, const vector& y);

// ----------------------------------------------------------------------
// struct matrix

struct matrix {
  matrix(int m, int n);
  ~matrix();

  double *vals;
  int m, n;
};

#ifdef BOUNDS_CHECK
#define MAT(M, i, j) (*({						\
	assert((i) >= 0 && (i) < (M).m);				\
	assert((j) >= 0 && (j) < (M).n);				\
	&((M).vals[(i) * (M).n + (j)]);					\
      })) 
#else
#define MAT(m, i, j) ((m).vals[(i) * (m).n + (j)])
#endif

void matrix_print(matrix& M);
void matrix_vector_mul(const matrix& A, const vector& x, vector& y);
void matrix_matrix_mul(const matrix& A, const matrix& B, matrix& C);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__) 

#endif
