
#include "linear_algebra.hxx"

#include <stdlib.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// vector::constructor
//
// construct a vector of length "n"

vector::vector(int n)
  : n_(n)
{
  vals_ = new double[n]{};
}

// ----------------------------------------------------------------------
// vector::constructor
//
// construct a vector of length "n" and set values

vector::vector(int n, const double* vals)
  : vector(n)
{
  for (int i = 0; i < n_; i++) {
    (*this)[i] = vals[i];
  }
}

// ----------------------------------------------------------------------
// vector::constructor from initializer list
//
// construct a vector of length "n" and set values

vector::vector(std::initializer_list<double> l)
  : vector(l.size())
{
  int i = 0;
  for (double val : l) {
    (*this)[i++] = val;
  }  
}

// ----------------------------------------------------------------------
// vector::destructor
//
// construct a vector of length "n" and set values

vector::~vector()
{
  delete[] vals_;
}

// ----------------------------------------------------------------------
// operator==

bool vector::operator==(const vector& other) const
{
  assert(n_ == other.n_);
  
  for (int i = 0; i < n_; i++) {
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
  os << "[(#=" << v.size() << ")";
  for (int i = 0; i < v.size(); i++) {
    os << " " << v[i];
  }
  os << "]";

  return os;
}

// ----------------------------------------------------------------------
// operator[]

double vector::operator[](int i) const
{
  return vals_[check_index(i)];
}

double& vector::operator[](int i)
{
  return vals_[check_index(i)];
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

// ----------------------------------------------------------------------
// size()
//
// returns # of elements in vector

int vector::size() const
{
  return n_;
}

