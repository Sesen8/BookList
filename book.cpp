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
using std::cout;
using std::endl;

// Implementation of Constructor that takes in name and year
Book::Book(string name, unsigned int year){
    _name = name;
    _isbn = "";
    _year = year;

}

// Implementation of Constructor that takes in name, isbn and year
// Remember to validate the ISBN
Book::Book(string name, string isbn, unsigned int year){
    _name = name;
    _isbn =isbn;
    _year = year;

}

// Implementation of Copy constructor
Book::Book(const Book &other) {


}

// Implementation of ToString method
// Format: Name of Book.ISBN.Year (Period separated values)
string Book::ToString() const {
    return _name + '.' + _isbn + '.' + std::to_string(_year);

}

// Implementation of ToJSON method
// Format: {"name":"Algorithm Design", "isbn":"0321295358", "year":2015}
string Book::ToJSON() const {

   // cout << "{\"name\":\"" + _name + "\", \"isbn\":\"" + _isbn + "\", \"year\":" + std::to_string(_year) + "}";
    return "{\"name\":\"" + _name + "\", \"isbn\":\"" + _isbn + "\", \"year\":" + std::to_string(_year) + "}";
}

// Implementation of ISBN getter/accessor method
string Book::GetISBN() const {
    return _isbn;
}

void Book::SetISBN(const string isbn) {
    _isbn = isbn;
}

// Implementation of Name getter/accessor method
string Book::GetName() const {
    return _name;
}

void Book::SetName(const string name) {
    _name = name;
}

// Implementation of Year getter/accessor method
int Book::GetYear() const {
    return _year;
}


void Book::SetYear(const int year) {
    _year = year;
}

// Implementation of Read from istream method
// Remember that each book is in a single line, and that the fields are separated by period
istream& Book::Read(istream &input) {
    string line;
    getline(input, line);

    size_t firstDot;
    firstDot = line.find(".",0);

    size_t secondDot;
    secondDot = line.find(".", firstDot+1);

    string name = line.substr(0,firstDot);

    string isbn = line.substr(firstDot+1,secondDot-firstDot-1);
    string year = line.substr(secondDot+1,string::npos);
    int newYear = stoi(year);



    this->SetName(name);
    this->SetISBN(isbn);
    this->SetYear(newYear);

    return input;

}

// Implementation of Write to ostream method
// This output *does not* include an end-line
ostream& Book::Write(ostream &output) const {

    string name1 = GetName();
    string isbn1 = GetISBN();
    int year1 = GetYear();

    output << name1 << "." << isbn1 << "." << year1;

    return output;
}


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
