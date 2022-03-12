//
// Created by Sesen Yonas on 3/10/22.
//
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
    while((selectedOption = MenuNew->Run()) != EXIT){


        // checks if user selected 1, adds book to list
        if (selectedOption == 0){
            if(bookList->Size() == 0){
                bookList->Clear();

            }


            string name;
            string isbn;
            int year;

            cout << "Enter the name of the book you would like to add... " << endl;

            //getline(cin, name);
            cin >>name;

            cout << "Enter the isbn of the book you would like to add... " << endl;

            cin >> isbn;

            cout << "Enter the year of the publising date of the book you would like to add... " << endl;

            cin >> year;

            bookList->AddBook(name,isbn,year);
            cout << "Book Added Successfully" << endl;

        }



        // checks if user selected 2, find a book
        if (selectedOption ==1){
            if(bookList->Size() == 0){
                cout << "Need to create array first!" << endl;
                continue;
            }

            string isbn;
            cout << "Input the isbn for the book you want to find ";
            cin >> isbn;
            cout << bookList->IndexOf(isbn) << endl;

        }


        // checks if user selected 2, get a book
        if (selectedOption ==2){
            if(bookList->Size() == 0){
                cout << "Need to create array first!" << endl;
                continue;
            }

            int position;
            cout << "Input the position of the book you want to find ";
            cin >> position;

            if (position < bookList->Size()) {
                cout << bookList->Get(position);
            }
            else {
                cout << "The position is invalid" << endl;

        }



        // checks if user selected 3, list added books
        if(selectedOption ==3){
            if(bookList->Size() == 0){
                cout << "Need to create list first!" << endl;
                continue;
            }
            cout << "Listing Books" << endl;
            cout << bookList->ToString() << endl;
        }


        // checks if user selected 4, removes selected book
        if(selectedOption ==4){
            if(bookList->Size() == 0){
                cout << "Need to create a list first!" << endl;
                continue;
            }

            cout <<"What is the position where you want to remove a book: ";
            int removePos;
            cin >> removePos;
            bookList->Remove(removePos);
            cout << "Book in position " << removePos << " removed successfully" << endl;

        }

        if(selectedOption ==5){
            if(bookList->Size() == 0){
                cout << "List is already empty" << endl;
                continue;
            }
            bookList->Clear();

        }


    }
    cout << "Finished the Program... Goodbye"<<endl<<endl;
    return 0;
}


}
