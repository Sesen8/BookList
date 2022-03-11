/**
 * Title:   Lab 4 - BookList class implementation.
 *
 * Purpose: ** your purpose here **
 * Class:   CSC 2430 Winter 2022
 * Author:  ** your name here **
 */
#include "book_list.h"
#include "book.h"

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
    _head = nullptr;
    _size =0;

}

/**
 * Destructor
 * Add your comments
 */
BookList::~BookList() {
    Node* tmp = _head;
    while(_head != nullptr){
        _head = tmp->next;
        tmp->next = nullptr;
        delete tmp;
        tmp = _head;
    }

}

/**
 * Add your comments
 * @param book to be added
 * @return always returns true
 */
bool BookList::AddBook(const Book &book) {
    Node* newNode = new Node();
    Book* newBook = new Book(book);
    newNode->book = newBook;
    newNode->next = _head;
    _head = newNode;

    _size++;

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

    Node* newNode =  new Node();
    Book* newBook = new Book(name,isbn,year);
    newNode->book = newBook;
    newNode->next = _head;
    _head = newNode;

    _size++;

    return true;
}

/**
 * Add your comments
 * @param name
 * @param year
 * @return always returns true
 */
bool BookList::AddBook(const string &name, unsigned int year) {

    Node* newNode =  new Node();
    Book* newBook = new Book(name,year);
    newNode->book = newBook;
    newNode->next = _head;
    _head = newNode;

    _size++;

    return true;
}

/**
 * Add your comments
 * @param isbn the isbn of the book the user is searching for
 * @return position of the book in the list if found, -1 otherwise
 */
int BookList::IndexOf(const string &isbn) const {

    int i = 0;
    for (Node* ptr = _head; ptr != nullptr; ptr = ptr->next){
        if (ptr->book->GetISBN() == isbn){
            return i;
        }
        i++;
    }

    return -1;
}

/**
 * Add your comments
 * @param position
 * @return
 */
const Book *BookList::Get(unsigned int position) const {

    Node* ptr = _head;
    if (position < _size){
        for (int i =0; i <position; i++){
            ptr = ptr->next;
        }
        if (ptr != nullptr) {
            return ptr->book;
        }
    }

    return nullptr;
}

/**
 * Add your comments
 * @param position
 * @return
 */
bool BookList::Remove(unsigned int position) {

    if (_head == nullptr){
        return false;
    }


    if (position == 0) {
        Node *nodeToDelete = _head;
        _head = _head->next;
        delete nodeToDelete;
        _size--;
        return true;
    }

    if (position < _size) {
        Node *tmp = _head;

        for (int i = 1; i < position - 1; i++) {
            if (tmp != nullptr) {
                tmp = tmp->next;
            }
        }

        if (tmp != nullptr && tmp->next != nullptr) {
            Node *nodeToDelete = tmp->next;
            tmp->next = tmp->next->next;
            delete nodeToDelete;
        }
        _size--;
        return true;
}

    return false;
}

/**
 * Add your comments.
 * Format for string to be returned:
 * [Book1Name.Book1ISBN.Book1Year, Book2Name.Book2ISBN, Book2Year, ...]
 * @return
 */
string BookList::ToString() const {

    if (_head == nullptr){
        return "[]";
    }

    Node* ptr = nullptr;
    string booklist = "[";
    for (ptr = _head; ptr->next != nullptr; ptr=ptr->next ){
        booklist+= ptr->book->ToString() + ", ";
    }



    booklist+= ptr->book->ToString() + "]";

    return booklist;
}

/**
 * Reads from an input stream, each book will be stored in the stream in a single line.
 * @param input stream to read from
 * @return input to allow stream chaining
 */
istream &BookList::Read(istream &input) {

    Book book("","",0);
    while (!input.eof()){
        if(input.peek() == -1) {
            break;
        }
        book.Read(input);
        AddBook(book);
    }

    return input;
}

/**
 * Writes to the output stream, each book should be stored in a single line.
 * @param output
 * @return output to allow stream chaining
 */
ostream &BookList::Write(ostream &output) const {

    for(Node* ptr = _head; ptr!= nullptr; ptr=ptr->next){
        ptr->book->Write(output) << endl;
    }

    return output;

}

/**
 * Add your comments
 */
void BookList::Clear() {

    Node* tmp = new Node;
    if (_head != nullptr){
        tmp = _head;
        _head = _head->next;
        delete tmp;
    }

    _head = nullptr;
    _size = 0;
}

/**
 * Add your comments
 * Example:
 * [{"name":"book one", "isbn":"1234567890", "year":1900}, {"name":"book two", "isbn":"0987654321", "year":1901}]
 * @return
 */
string BookList::ToJSON() const {

    if (_head == nullptr){
        return "[]";
    }

    Node* ptr = nullptr;
    string booklist = "[";
    for (ptr = _head; ptr->next != nullptr; ptr=ptr->next ){
        booklist+= ptr->book->ToJSON() + ", ";
    }



    booklist += ptr->book->ToJSON() + "]";

    return booklist;
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
