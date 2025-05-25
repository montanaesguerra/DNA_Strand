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

// Returns the Base at the given index
DNAStrand::Base DNAStrand::at(int index) const {
  if (index < 0 || index >= length) {
    throw std::out_of_range("Index is less than 0 or too large");
  }

  return bases[index];
}

// Returns string form of this DNAStrand
std::string DNAStrand::toString() const {
  std::string stringForm = "";

  char c;

  for (int i = 0; i < length; ++i) {
    c = baseToChar(bases[i]);
    stringForm += c;
  }

  return stringForm;
}

// Comparison Operator ==
bool DNAStrand::operator==(const DNAStrand& other) const {
  // Check lengths first
  if (this->length != other.length) {
    return false;
  }

  for (int i = 0; i < length; ++i) {
    if (baseToChar(this->bases[i]) != baseToChar(other.bases[i]))
      return false;
  }

  return true;
}

// Copy Constructor
DNAStrand::DNAStrand(const DNAStrand& other) {
  this->length = other.length;
  this->bases = new Base[length];

  for (int i = 0; i < length; ++i) {
    this->bases[i] = other.bases[i];
  }
}

// Assignment Operator
DNAStrand& DNAStrand::operator=(const DNAStrand& other) {
  if (this == &other) {
    return *this;
  }

  // Clean up
  delete[] bases;

  // Copy new values
  length = other.length;
  bases = new Base[length];

  for (int i = 0; i < length; ++i) {
    bases[i] = other.bases[i];
  }

  return *this;
}

//Concatenation operator
DNAStrand DNAStrand::operator+(const DNAStrand& other) const {

  DNAStrand result("");

  result.length = this->length + other.length;
  result.bases = new Base[result.length];

  // Copy first strand
  for (int i = 0; i < this->length; ++i) {
    result.bases[i] = this->bases[i];
  }

  // Copy second strand
  for (int i = 0; i < other.length; ++i) {
    result.bases[this->length + i] = other.bases[i];
  }

  return result;
}

// getComplement
DNAStrand DNAStrand::getComplement() const {
  DNAStrand complement("");
  complement.length = this->length;
  complement.bases = new Base[complement.length];

  for (int i = 0; i < length; ++i) {
    switch (bases[i]) {
      case A:
        complement.bases[i] = T;
        break;
      
      case T:
        complement.bases[i] = A;
        break;

      case C:
        complement.bases[i] = G;
        break;
      
      case G:
        complement.bases[i] = C;
        break;
    }
  }
  return complement;
}

//SubStrand
DNAStrand DNAStrand::substr(int start, int substrLength) const {

  if (start < 0 || substrLength < 0 || start + substrLength > length) {
    throw std::out_of_range("Bad Start or Bad Length Detected");
  }

  DNAStrand result("");
  result.length = substrLength;
  result.bases = new Base[substrLength];

  for (int i = 0; i < substrLength; ++i) {
    result.bases[i] = this->bases[start + i];
  }

  return result;
}

// Destructor
DNAStrand::~DNAStrand() {
  delete[] bases;
}

