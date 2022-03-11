//
// Created by Sesen Yonas on 3/10/22.
//
#include "menu_copy.h"
#include "book.h"
#include <string>
#include <iostream>


using std::cout;
using std::cin;
using std::endl;
//using std::setw;
using std::fixed;
//using std::setprecision;
using std::ostream;
using std::istream;


int main(int argc, char* argv[]) {

    Menu *MenuNew;

    MenuNew = new Menu(7, cout, cin, cerr);

    MenuNew->SetErrorMessage("- - > Unrecognized Input < - -");
    MenuNew->SetInvalidOption("- - > Please Input One of the Given Choices < - -");
    MenuNew->SetInputType(INT);
    MenuNew->SetTitle("Book Store");

    MenuNew->AddMenuOption(0, "1", ". Add a Book");
    MenuNew->AddMenuOption(1, "2", ". Find a Book");
    MenuNew->AddMenuOption(2, "3", ". Get a Book");
    MenuNew->AddMenuOption(3, "4", ". List all Books");
    MenuNew->AddMenuOption(4, "5", ". Remove one Book");
    MenuNew->AddMenuOption(5, "6", ". Remove all Books");


    int selectedOption;



    int option = 0;

    while((selectedOption = MenuNew->Run()) != EXIT){

        if (selectedOption == 0) {
            cout << "Please input the name of the book, its isbn number and the publishing date";
            string line;
            istream input;
            getline(input,line);



        }

        if (selectedOption == 1) {

        }

        if (selectedOption == 2) {

        }

        if (selectedOption == 3) {

        }

        if (selectedOption == 4) {

        }

        if (selectedOption == 5) {

        }

        if (selectedOption == 6) {

        }



        }

    }
