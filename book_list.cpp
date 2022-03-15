/**
 * Title:   Lab 4 - BookList class implementation.
 *
 * Purpose: ** This program inlcudes the implementation of the booklist class methods **
 *          ** to add, remove, clear, find, convert books to a booklist.**
 *
 * Class:   CSC 2430 Winter 2022
 * Author:  ** Sesen Yonas **
 */


#include "book_list.h"
#include "book.h"
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
 * @this method adds an entire book to the list
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
 * @this method adds a book with a name, isbn number and publishing date
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
 * @this method adds a book with a name, isbn number and publishing date
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
 * This function takes in an isbn as a parameter, iterates through
 * the list to find the position of the given isbn.
 *
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
 * This method is to remove a book from the list
 *
 * @param position
 * @return false if _head is null or if the position is invalid
 */
bool BookList::Remove(unsigned int position) {
    // checks if head is null
    if (_head == nullptr){
        return false;
    }
    // deletes if the positon in the first node
    if (position == 0) {
        Node *nodeToDelete = _head;
        _head = _head->next;
        delete nodeToDelete;
        _size--;
        return true;
    }
    // checks if position is valid, if it is, program continues to try and delete
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
    // if position is in valid
    return false;
}



/**
 * This method iterates through the linked list taking each book and
 * printing it out in a string format all on one line
 *
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
 *
 * @param input stream to read from
 * @return input to allow stream chaining
 */
istream &BookList::Read(istream &input) {

    Book book("","",0);
    while (!input.eof()){
        if(input.peek() == -1) { //parker lab assistant helped debugged to use -1 as break number
            break;
        }
        book.Read(input);
        AddBook(book);
    }

    return input;
}

/**
 * Writes to the output stream, each book should be stored in a single line.
 *
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
 * This method is called to clear the entire linked list and
 * initialize the head and size to default values of
 * null and zero
 *
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
 * This method iterates through the linked list taking each book and
 * printing it out in a json format all on one line
 *
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
 * This method is called to find out the current size of the list
 *
 * @return
 */
unsigned int BookList::Size() const {

    return _size;
}




/**
 * this is a copy constructor
 *
 * @param book
 */
BookList::Node::Node(const Book &book) {
    this->book = new Book(book);
    next = nullptr;
}




/** Defualt constructor
 *
 */
BookList::Node::Node() {
    book = nullptr;
    next = nullptr;
}
