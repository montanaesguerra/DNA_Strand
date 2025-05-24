//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#include "DNAStrand.h"
#include <stdexcept>
#include <string>
using namespace std;

// Helpers:
char DNAStrand::baseToChar(Base b)
{
  switch (b) {
  case A:
    return 'A';
  case C:
    return 'C';
  case G:
    return 'G';
  case T:
    return 'T';
  default:
    throw logic_error("Invalid base value: " + to_string(b));
  }
}

DNAStrand::Base DNAStrand::charToBase(char c)
{
  switch (c) {
  case 'A':
    return A;
  case 'C':
    return C;
  case 'G':
    return G;
  case 'T':
    return T;
  default:
    throw logic_error(string("Char does not denote a base: ") + c);
  }
}

int DNAStrand::getLength() const
{
  return length;
}
