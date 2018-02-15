
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
    (*this)[i] = vals[i];
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
// operator==

bool vector::operator==(const vector& other) const
{
  for (int i = 0; i < n; i++) {
    if ((*this)[i] != other[i]) {
      return false;
    }
  }
  return true;
}

// ----------------------------------------------------------------------
// operator<<
//
// prints vector "v"

std::ostream& operator<<(std::ostream& os, const vector& v)
{
  os << "[(#=" << v.n << ")";
  for (int i = 0; i < v.n; i++) {
    os << " " << v[i];
  }
  os << "]";

  return os;
}

// ----------------------------------------------------------------------
// operator[]

double vector::operator[](int i) const
{
  return vals[check_index(i)];
}

double& vector::operator[](int i)
{
  return vals[check_index(i)];
}

// ----------------------------------------------------------------------
// check_index

int vector::check_index(int i) const
{
#ifdef BOUNDS_CHECK
  assert(i >= 0);
  assert(i < n);
#endif
  return i;
}
  

