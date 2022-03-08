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
    Book (string name,unsigned int year);

    // Constructor that takes in name, isbn and year
    Book(string name, string isbn, unsigned int year);

    // Copy constructor
    Book(const Book& other);

    // ToString method
    string ToString()const;

    // ToJSON method
    string ToJSON()const;

    // ISBN getter/accessor method
    string GetISBN()const;
    void SetISBN(const string isbn);

    // Name getter/accessor method
    string GetName()const;
    void SetName(const string name);

    // Year getter/accessor method
    int GetYear()const;
    void SetYear(const int year);

    // Read from istream method
    istream& Read(istream& input);

    // Write to ostream method
    ostream& Write(ostream& output)const;
};

 bool IsValidISBN(const string& isbn);

#endif //LINKED_LIST_A_BOOK_H
