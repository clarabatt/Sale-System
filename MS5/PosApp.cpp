// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 12/03/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#include "PosApp.h"
#include "Utils.h"
#include "iostream"
#include "iomanip"
#include <cstring>

using namespace std;

namespace sdds {

    PosApp::PosApp(const char filename[]){
        if (filename[0] != '\0')
            strcpy(this->filename, filename);
    };

    int PosApp::menu(){

        char choice[4] = {'\0'};
        double num = -1;
        bool firstLoop = true;

        cout << "The Sene-Store" << endl;
        cout << "1- List items" << endl;
        cout << "2- Add item" << endl;
        cout << "3- Remove item" << endl;
        cout << "4- Stock item" << endl;
        cout << "5- Point of Sale" << endl;
        cout << "0- exit program" << endl;

        while(num != 1 and num != 2 and num != 3 and num != 4 and num != 5 and num != 0){
            if (firstLoop) {
                cout << "> ";
            } else {
                if (!isdigit(choice[0]) and !isdigit(choice[1]))
                    cout << "Invalid Integer, try again: ";
                else if (stod(choice) < 0 or stod(choice) > 5)
                    cout << "[0<=value<=5], retry: > ";
            }

            cin >> choice;
            flushkeys();
            if (isdigit(choice[0]))
                num = stod(choice);
            firstLoop = false;
        }

        return int(num);
    }

    void PosApp::run(){
        int val = -1;
        loadRecs();
        while (val != 0) {
            val = menu();

            if (val == 1) {
                listItems();
            } else if (val == 2) {
                addItem();
            } else if (val == 3) {
                removeItem();
            } else if (val == 4) {
                stockItem();
            } else if (val == 5) {
                POS();
            } else if (val == 0) {
                saveRecs();
            }
        }
    };

    void PosApp::addItem(){
        cout << ">>>> " << setw(71) << setfill('.') << left << "Adding Item to the store" << "." << endl;
        cout << "Running" << " addItem()" << endl;
    };
    void PosApp::removeItem(){
        cout << ">>>> " << setw(71) << setfill('.') << left << "Remove Item" << "." << endl;
        cout << "Running" << " removeItem()" << endl;
    };
    void PosApp::stockItem(){
        cout << ">>>> " << setw(71) << setfill('.') << left << "Select an item to stock" << "." << endl;
        cout << "Running" << " stockItem()" << endl;
    };
    void PosApp::listItems(){
        cout << ">>>> " << setw(71) << setfill('.') << left << "Listing Items" << "." << endl;
        cout << "Running" << " listItems()" << endl;
    };
    void PosApp::POS(){
        cout << ">>>> " << setw(71) << setfill('.') << left << "Starting Point of Sale" << "." << endl;
        cout << "Running" << " POS()" << endl;
    };
    void PosApp::saveRecs(){
        cout << ">>>> " << setw(71) << setfill('.') << left << "Saving Data" << "." << endl;
        cout << "Saving data in datafile.csv\n"
                "Goodbye!" << endl;
    };
    void PosApp::loadRecs(){
        cout << ">>>> " << setw(71) << setfill('.') << left << "Loading Items" << "." << endl;
        cout << "Loading data from datafile.csv" << endl;
    };
}
