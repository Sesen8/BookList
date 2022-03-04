/**
 * Title:   Lab 4 - BookList class implementation.
 *
 * Purpose: ** your purpose here **
 * Class:   CSC 2430 Winter 2022
 * Author:  ** your name here **
 */
#include "book_list.h"

#include <sstream>
#include <string>
#include <iostream>
using std::string;
using std::stringstream;
using std::ostream;
using std::istream;
using std::endl;

/**
 * Copy Constructor of the Book List
 * You don't need to implement this method.
 * @param other the original BookList that is going to be copied.
 */
BookList::BookList(const BookList &other) {
}
/**
 * Copy Assignment operator of the Book List
 * You don't need to implement this method.
 * @param rhs The right hand side operand of the assignment.
 * @return a reference to the caller object
 */
BookList &BookList::operator=(const BookList &rhs) {
    return *this;
}
/**
 * Default constructor
 * Add your comments
 */
BookList::BookList() {
    // Add your code
}
/**
 * Destructor
 * Add your comments
 */
BookList::~BookList() {
    // Add your code
}
/**
 * Add your comments
 * @param book to be added
 * @return always returns true
 */
bool BookList::AddBook(const Book &book) {
    // Add your code
    return true;
}
/**
 * Add your comments
 * @param name
 * @param isbn
 * @param year
 * @return always returns true
 */
bool BookList::AddBook(const string &name, const string &isbn, unsigned int year) {
    // Add your code
}
/**
 * Add your comments
 * @param name
 * @param year
 * @return always returns true
 */
bool BookList::AddBook(const string &name, unsigned int year) {
    // Add your code
}
/**
 * Add your comments
 * @param isbn the isbn of the book the user is searching for
 * @return position of the book in the list if found, -1 otherwise
 */
int BookList::IndexOf(const string &isbn) const {
    // Add your code
    return -1;
}
/**
 * Add your comments
 * @param position
 * @return
 */
const Book *BookList::Get(unsigned int position) const {
    // Add your code
    return nullptr;
}
/**
 * Add your comments
 * @param position
 * @return
 */
bool BookList::Remove(unsigned int position) {
    // Add your code
    return true;
}
/**
 * Add your comments.
 * Format for string to be returned:
 * [Book1Name.Book1ISBN.Book1Year, Book2Name.Book2ISBN, Book2Year, ...]
 * @return
 */
string BookList::ToString() const {
    // Add your code
    return "";
}
/**
 * Reads from an input stream, each book will be stored in the stream in a single line.
 * @param input stream to read from
 * @return input to allow stream chaining
 */
istream &BookList::Read(istream &input) {
    // Add your code
    return input;
}
/**
 * Writes to the output stream, each book should be stored in a single line.
 * @param output
 * @return output to allow stream chaining
 */
ostream &BookList::Write(ostream &output) const {
    // Add your code
    return output;
}
/**
 * Add your comments
 */
void BookList::Clear() {
    // Add your code
}
/**
 * Add your comments
 * Example:
 * [{"name":"book one", "isbn":"1234567890", "year":1900}, {"name":"book two", "isbn":"0987654321", "year":1901}]
 * @return
 */
string BookList::ToJSON() const {
    // Add your code
    return "";
}
/**
 * Add your comments
 * @return
 */
unsigned int BookList::Size() const {
    return _size;
}
/**
 * Add your comments
 * @param book
 */
BookList::Node::Node(const Book &book) {
    this->book = new Book(book);
    next = nullptr;
}

/** Add your comments
 *
 */
BookList::Node::Node() {
    book = nullptr;
    next = nullptr;
}
