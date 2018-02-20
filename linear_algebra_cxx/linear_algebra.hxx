
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <iostream>
#include <initializer_list>

#include <assert.h>

//#define BOUNDS_CHECK

// FIXME:
// Let's put a big FIXME here: the default copy constructors on
// vector and matrix will not do the right thing. The tests aren't
// using them (at least not quite), so we're good for now, but
// if this was to be seriously used, it'd definitely need fixing

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

  double  operator()(int i, int j) const;
  double& operator()(int i, int j);

  int index(int i, int j) const;
  
  double *vals;
  int m, n;
};

std::ostream& operator<<(std::ostream& os, const matrix& v);

vector operator*(const matrix& A, const vector& x);
matrix operator*(const matrix& A, const matrix& B);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__) 

#endif
