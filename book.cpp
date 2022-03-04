/**
 * Title:   Lab 4 - Book class implementation
 *
 * Purpose: ** your purpose here **
 * Class:   CSC 2430 Winter 2022
 * Author:  ** your name here **
 */
#include "book.h"

#include <string>
#include <iostream>
#include <sstream>

using std::string;
using std::ostream;
using std::istream;
using std::stringstream;

// Implementation of Constructor that takes in name and year

// Implementation of Constructor that takes in name, isbn and year
// Remember to validate the ISBN

// Implementation of Copy constructor

// Implementation of ToString method
// Format: Name of Book.ISBN.Year (Period separated values)

// Implementation of ToJSON method
// Format: {"name":"Algorithm Design", "isbn":"0321295358", "year":2015}

// Implementation of ISBN getter/accessor method

// Implementation of Name getter/accessor method

// Implementation of Year getter/accessor method

// Implementation of Read from istream method
// Remember that each book is in a single line, and that the fields are separated by period

// Implementation of Write to ostream method
// This output *does not* include an end-line


/**
 * This function checks if the string passed as parameter, isbn, represents a valid
 * isbn. To implement this function you will need to do research on how to validate ISBN.
 * Both ISBN10 and ISBN13 are expected to work with this function.
 * @param isbn the isbn that is going to be checked
 * @return true if the isbn given is a valid isbn, false otherwise
 */
bool IsValidISBN(const string& isbn){
    // Add your code
}
