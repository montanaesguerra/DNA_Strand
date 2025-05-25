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

// Constructor
DNAStrand::DNAStrand(const std::string& startingString) {
  //Set the length of DNAString
  length = startingString.length();

  //Set the Bases array to the lenth of startingString
  bases = new Base[length];

  for (int i = 0; i < length; ++i) {
    
    //pass each character in startingString
    //to the Base array, converting each char to Base.
    char c = startingString[i];

    bases[i] = charToBase(c); 
  }

}

DNAStrand::Base DNAStrand::at(int index) const {
  if (index < 0 || index >= length) {
    throw std::out_of_range("Index is less than 0 or too large");
  }
  
  return bases[index];
}

// Destructor
DNAStrand::~DNAStrand() {
  delete[] bases;
}

