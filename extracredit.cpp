/**
 * Title:   Lab 4 Extra Credit - Book Store Implementation
 *
 * Purpose: ** This program includes implementations of book store menu **
 *          ** to allow user input for adding, finding, getting, listing **
 *          ** removing and clearing books in the "book store" list. Uses**
 *          ** code from lab 3 menu assignment for the run and implementation **
 *          ** of the menu class. **
 *
 * Class:   CSC 2430 Winter 2022
 * Author:  ** Sesen Yonas **
 */

#include "menu_copy.h"
#include "menu_element_copy.h"
#include "book.h"
#include "book_list.h"
#include <string>
#include <iostream>


using std::cout;
using std::getline;
using std::cin;
using std::endl;
//using std::setw;
using std::fixed;
//using std::setprecision;
using std::ostream;
using std::istream;


int main(int argc, char* argv[]) {

    Menu *MenuNew;

    MenuNew = new Menu(6, cout, cin, cerr);

    MenuNew->SetErrorMessage("- - > Unrecognized Input < - -");
    MenuNew->SetInvalidOption("- - > Please Input One of the Given Choices < - -");

    MenuNew->SetTitle("Book Store");

    MenuNew->AddMenuOption(0, "1", ". Add a Book");
    MenuNew->AddMenuOption(1, "2", ". Find a Book");
    MenuNew->AddMenuOption(2, "3", ". Get a Book");
    MenuNew->AddMenuOption(3, "4", ". List all Books");
    MenuNew->AddMenuOption(4, "5", ". Remove one Book");
    MenuNew->AddMenuOption(5, "6", ". Remove all Books");


    int selectedOption;
    BookList* bookList = new BookList();



    int option = 0;

    // RUNS IF SELECTION OPTION IS NOT EXIT
    while((selectedOption = MenuNew->Run()) != EXIT){


        // CHECKS IF USER SELECTED MENU OPTION 1, ADDS A BOOK TO A LIST
        if (selectedOption == 0) {
            if (bookList->Size() == 0) {
                bookList->Clear();
            }
            string name;
            string isbn;
            string yearString;
            int yearInt;

            cin.ignore(); // help from lab assistant ethan
            cout << "Enter the name of the book you would like to add: " << endl;
            //getline(cin, name);
            getline(cin, name);
            cout << "Enter the isbn of the book you would like to add: " << endl;
            getline(cin, isbn);
            cout << "Enter the publising year of the book you would like to add: " << endl;
            getline(cin, yearString);

            yearInt = stoi(yearString);

            if (IsValidISBN(isbn) != true) {
                cout << "Sorry please enter a book with Isbn 10 or Isbn 13 format" << endl;
                cout << endl;
            }

            else {
            bookList->AddBook(name, isbn, yearInt);
            cout << "Book Added Successfully!" << endl;
            cout << endl;
            }




        }





        // CHECKS IF USER SELECTED MENU OPTION 2, FINDS A BOOK
        if (selectedOption ==1){
            if(bookList->Size() == 0){
                cout << "Need to create list first!" << endl;
                cout << endl;
                continue;
            }
            string isbn;
            cout << "Input the isbn for the book you want to find ";
            cin >> isbn;
            if (bookList->IndexOf(isbn) != -1){
                const Book* book = bookList->Get(bookList->IndexOf(isbn));
                cout << "Congrats! We found your book! " << book->ToString() << endl;
            }
            else {
                cout << "Sorry we couldn't find your book!" << endl;
            }
            cout << endl;
        }





        // CHECKS IF USER SELECTED MENU OPTION 3, GETS A BOOK
        if (selectedOption ==2) {
            if (bookList->Size() == 0) {
                cout << "Need to create list first!" << endl;
                cout << endl;
                continue;
            }
            int position;
            cout << "Input the position of the book you want to find: ";
            cin >> position;
            if (position < bookList->Size()) {
                if(bookList->Get(position) != nullptr){
                    const Book* book = bookList->Get(position);
                    cout << "The book at position " << position << " is " << book->ToString() << endl;
                }
                cout << endl;
            } else {
                cout << "Sorry this position is invalid!" << endl;
                cout << endl;
            }
        }



        // CHECKS IF USER SELECTED MENU OPTION 4, LISTS ADDED BOOKS
        if(selectedOption ==3){
            if(bookList->Size() == 0){
                cout << "Need to create list first!" << endl;
                cout << endl;
                continue;
            }
            cout << "Listing Books" << endl;
            cout << bookList->ToString() << endl;
            cout << endl;
        }




        // CHECKS IF USER SELECTED MENU OPTION 5, REMOVES SELECTED BOOK
        if(selectedOption ==4){
            if(bookList->Size() == 0){
                cout << "Need to create a list first!" << endl;
                cout << endl;
                continue;
            }
            cout <<"What is the position of the book you want to remove: ";
            int removePos;
            cin >> removePos;

            if (bookList->Get(removePos) == nullptr){
                cout << "Sorry that seems to be an invalid position" << endl;
                cout << endl;
            }
            else {
                bookList->Remove(removePos);
                cout << "Book in position " << removePos << " removed successfully" << endl;
                cout << endl;
            }
        }




        // CHECKS IF USER SELECTED MENU OPTION 6, REMOVES ALL BOOKS IN LIST
        if(selectedOption ==5){
            if(bookList->Size() == 0){
                cout << "List is already empty" << endl;
                cout << endl;
                continue;
            }
            bookList->Clear();
            cout << "List Cleared Successfully" << endl;
            cout << endl;

        }


    }

    cout << "Finished the Program... Goodbye"<<endl<<endl;
    return 0;
}



