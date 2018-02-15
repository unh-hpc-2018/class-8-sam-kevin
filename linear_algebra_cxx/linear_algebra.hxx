
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <iostream>

#include <assert.h>

//#define BOUNDS_CHECK

// ----------------------------------------------------------------------
// struct vector

class vector
{
public:
  vector(int n);
  vector(int n, const double* vals);
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
  double *vals;
  int m, n;
};

#ifdef BOUNDS_CHECK
#define MAT(M, i, j) (*({						\
	assert((i) >= 0 && (i) < (M)->m);				\
	assert((j) >= 0 && (j) < (M)->n);				\
	&((M)->vals[(i) * (M)->n + (j)]);				\
      })) 
#else
#define MAT(m, i, j) ((m)->vals[(i) * (m)->n + (j)])
#endif

struct matrix *matrix_create(int m, int n);
void matrix_destroy(struct matrix *M);
void matrix_print(struct matrix *M);
void matrix_vector_mul(const struct matrix *A, const vector& x, vector& y);
void matrix_matrix_mul(const struct matrix *A, const struct matrix *B, struct matrix *C);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__) 

#endif
