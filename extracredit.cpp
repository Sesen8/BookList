//
// Created by Sesen Yonas on 3/10/22.
//
#include "menu_copy.h"
#include "menu_element_copy.h"
#include "book.h"
#inlcude "book_list.h"
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
    Node* bookList = nullptr;



    int option = 0;
    while((selectedOption = MenuNew->Run()) != EXIT){


        // checks if user selected 1, creates array
        if (selectedOption == 0){
            if(bookList != nullptr){
                delete[] createdArray;
                cout << "The created list will be lost" << endl;
            }
            cout << "Please input the maximum capacity of the array: ";
            cin >> sizeofArray;

            while(sizeofArray < 0){
                cout << "Please input the maximum capacity of the array: " << endl;
                cin >> sizeofArray;
            }
            createdArray = new double[sizeofArray];
            cout << "Array Created Successfully" << endl;
            option = 0;
        }



        // checks if user selected 2, adds numbers to array
        if (selectedOption ==2){
            if(createdArray == nullptr){
                cout << "Need to create array first!" << endl;
                continue;
            }
            double userAdd;
            if(option >= sizeofArray){
                cout <<"Array is full" << endl;
                continue;
            }
            cout << "Adding Number to Array" << endl;
            cout << "Please input the number you want to add: ";
            cin >> userAdd;


            createdArray[option] = userAdd;
            cout << "Number "<< userAdd<< " Added to Position "<<option<< " Successfully" << endl;
            option+=1;
        }


        // checks if user selected 3, lists added numbers
        if(selectedOption ==3){
            if(createdArray == nullptr){
                cout << "Need to create array first!" << endl;
                continue;
            }
            cout << "Listing Numbers" << endl;
            for(int i =0; i<option; i++){
                cout << i << " " << createdArray[i] << endl;
            }
        }


        // checks if user selected 4, removes selected number
        if(selectedOption ==4){
            if(createdArray == nullptr){
                cout << "Need to create array first!" << endl;
                continue;
            }
            for(int i =0; i<option; i++){
                cout << i << " " << createdArray[i] << endl;
            }

            cout <<"What is the position where you want to remove a number: ";
            int removePos;
            cin >> removePos;
            if (removePos >=0 && removePos < option){
                for (int i = removePos; i<option-1; i++){
                    createdArray[i] = createdArray[i+1];
                }
                cout << "Number in Position 0 Removed Successfully" << endl;
                option = option -1;
            }
            else {
                cout << "Invalid Position" << endl;
            }

        }


        // checks if user selected 5, calculates the average of array
        if (selectedOption == 6){
            if(createdArray == nullptr){
                cout << "Need to create array first!" << endl;
                continue;
            }
            double total = 0.0;
            for (int i = 0; i<option; i++){
                total+=createdArray[i];
            }
            double average = total/option;
            cout << "The average is " << average << endl;
        }


    }
    cout << "Finished the Program... Goodbye"<<endl<<endl;
    return 0;
}


}
