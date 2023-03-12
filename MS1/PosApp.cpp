#include "PosApp.h"
#include "Utils.h"
#include "iostream"

using namespace std;

namespace sdds {

    PosApp::PosApp(char * filename){
        if (filename[0] != '\0')
            strcpy(this->filename, filename);
    };

    int PosApp::menu(){

        int choice = -1;
        bool firstLoop = true;

        cout << "The Sene-Store" << endl;
        cout << "1- List items" << endl;
        cout << "2- Add item" << endl;
        cout << "3- Remove item" << endl;
        cout << "4- Stock item" << endl;
        cout << "5- Point of Sale" << endl;
        cout << "0- exit program" << endl;

        while(choice != 1 and choice != 2 and choice != 3 and choice != 4 and choice != 5 and choice != 6){
            if (firstLoop) {
                cout << "> ";
            } else {
                if (choice > 5 or choice < 0)
                    cout << "[0<=value<=5], retry: > ";
                else
                    cout << "Invalid Integer, try again: ";
            }
            cin >> choice;
            flushkeys();
            firstLoop = false;
        }

        return choice;

    }

    void PosApp::run(){
        int val = menu();

        if (val == 1){
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
            cout << "Saving data in datafile.csv\n"
                    "Goodbye!";
        }

    };

    void PosApp::addItem(){
        cout << "Running" << " addItem()" << endl;
    };
    void PosApp::removeItem(){
        cout << "Running" << " removeItem()" << endl;
    };
    void PosApp::stockItem(){
        cout << "Running" << " stockItem()" << endl;
    };
    void PosApp::listItems(){
        cout << "Running" << " listItems()" << endl;
    };
    void PosApp::POS(){
        cout << "Running" << " POS()" << endl;
    };
    void PosApp::saveRecs(){
        cout << "Running" << " saveRecs()" << endl;
    };
    void PosApp::loadRecs(){
        cout << "Running" << " loadRecs()" << endl;
    };
}