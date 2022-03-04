/**
 * Title:   Lab 4 - Book Class Declaration
 *
 * Purpose: Declares the class Book
 *          You may add methods additional methods
 *          You must declare and define the methods listed/described below
 * Class:   CSC 2430 Winter 2022
 * Author:  Carlos R. Arias
 * Author:  ** Your name here **
 */
#ifndef LINKED_LIST_A_BOOK_H
#define LINKED_LIST_A_BOOK_H

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

class Book {
private:
    string _name;
    string _isbn;
    unsigned int _year;
public:
    // Constructor that takes in name and year
    // Constructor that takes in name, isbn and year
    // Copy constructor
    // ToString method
    // ToJSON method
    // ISBN getter/accessor method
    // Name getter/accessor method
    // Year getter/accessor method
    // Read from istream method
    // Write to ostream method
};

 bool IsValidISBN(const string& isbn);

#endif //LINKED_LIST_A_BOOK_H
