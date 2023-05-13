#include "PosApp.h"
#include "Utils.h"
#include "Date.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include "iostream"
#include "iomanip"
#include <cstring>
#include <fstream>

using namespace std;

namespace sdds
{

    PosApp::PosApp(const char filename[])
    {
        if (filename[0] != '\0')
            strcpy(this->filename, filename);
    };

    PosApp::~PosApp()
    {
        for (int i = 0; i < nptr; i++)
        {
            delete Iptr[i];
        }
        nptr = 0;
    }

    int PosApp::menu()
    {

        char choice[4] = {'\0'};
        double num = -1;
        bool firstLoop = true;

        cout << "The Sene-Store" << endl;
        cout << "1- List items" << endl;
        cout << "2- Add item" << endl;
        cout << "3- Remove item" << endl;
        cout << "4- Stock item" << endl;
        cout << "5- POS" << endl;
        cout << "0- exit program" << endl;

        while (num != 1 and num != 2 and num != 3 and num != 4 and num != 5 and num != 0)
        {
            if (firstLoop)
            {
                cout << "> ";
            }
            else
            {
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

    void PosApp::run()
    {
        int val = -1;
        loadRecs();
        while (val != 0)
        {
            val = menu();

            if (val == 1)
            {
                listItems();
            }
            else if (val == 2)
            {
                addItem();
            }
            else if (val == 3)
            {
                removeItem();
            }
            else if (val == 4)
            {
                stockItem();
            }
            else if (val == 5)
            {
                POS();
            }
            else if (val == 0)
            {
                saveRecs();
            }
        }
    };

    void PosApp::clearItems()
    {
        if (nptr != 0)
        {
            for (int i = 0; i < nptr; i++)
            {
                if (Iptr[i] != nullptr)
                {
                    delete Iptr[i];
                    Iptr[i] = nullptr;
                }
            }
            nptr = 0;
        }
    };

    void PosApp::addItem()
    {
        actionTitle("Adding Item to the store");
        if (nptr >= MAX_NO_ITEMS)
        {
            cout << "Inventory Full!";
            return;
        }
        Item *temp;
        char type;
        cout << "Is the Item perishable? (Y)es/(N)o: ";
        cin >> type;
        if (type == 'y')
            temp = new Perishable();
        else
            temp = new NonPerishable();
        cin.ignore();
        while (!temp->read(cin))
        {
            cin.clear();
            flushkeys();
            cout << ", try again...\n";
        }
        Iptr[nptr] = temp;
        nptr++;
        actionTitle("DONE!");
    };
    void PosApp::removeItem()
    {
        actionTitle("Remove Item");
        int selec = selectItem() - 1;
        cout << "Removing...." << endl;
        Iptr[selec]->displayType(POS_FORM);
        Iptr[selec]->write(cout);

        delete Iptr[selec];
        Iptr[selec] = nullptr;

        for (int i = selec + 1; i < nptr; i++)
        {
            Iptr[i - 1] = Iptr[i];
        }
        nptr--;
        actionTitle("DONE!");
    };
    void PosApp::stockItem()
    {
        actionTitle("Select an item to stock");
        int row = selectItem();
        cout << "Selected Item:\n";
        Iptr[row - 1]->displayType(POS_FORM);
        Iptr[row - 1]->write(cout);

        bool done = true;
        int num = 0;
        int maxItems = MAX_STOCK_NUMBER - Iptr[row - 1]->quantity();

        cout << "Enter quantity to add: ";
        while (done)
        {
            cin >> num;
            if (cin.fail())
            {
                cout << "Invalid Integer, try again: ";
                cin.clear();
                cin.ignore(2000, '\n');
            }
            else if (num < 1 or num > maxItems)
            {
                cout << "[1<=value<=" << maxItems << "], retry: ";
                cout << "Enter quantity to add: ";
            }
            else
            {
                Iptr[row - 1]->operator+=(num);
                done = false;
            }
        }
        actionTitle("DONE!");
    };
    void PosApp::POS()
    {
        actionTitle("Starting Point of Sale");

        bool done = true;
        char num[MAX_SKU_LEN + 1];
        int countBill = 0;
        double sumtotal = 0;
        int *indexList = new int[nptr];

        while (done)
        {
            cout << "Enter SKU or <ENTER> only to end sale...\n"
                 << "> ";
            cin.getline(num, MAX_SKU_LEN + 1);
            if (strlen(num) == 0)
            {
                done = false;
                break;
            }

            if (cin.fail())
            {
                cout << "SKU too long";
                cin.clear();
                cin.ignore(2000, '\n');
            }
            else
            {
                int index = search(stoi(num));
                if (index >= 0 && Iptr[index]->quantity() <= 0)
                {
                    cout << "Item out of stock" << endl;
                }
                else if (index >= 0 && Iptr[index]->quantity() > 0)
                {
                    Iptr[index]->operator-=(1);
                    Iptr[index]->displayType(POS_FORM);
                    Iptr[index]->write(cout);
                    indexList[countBill] = index;
                    countBill++;
                    sumtotal += Iptr[index]->cost();
                    cout << endl
                         << ">>>>> Added to bill" << endl;
                    cout << ">>>>> Total: " << fixed << setprecision(2) << sumtotal << endl;
                }
            }
        }

        Date dateNow;
        dateNow.dateOnly(false);

        cout << "v---------------------------------------v" << endl;
        cout << "| ";
        dateNow.display(cout);
        cout << "                     |" << endl;
        cout << "+---------------------v-----------v-----+" << endl;
        cout << "| Item                |     Price | Tax +" << endl;
        cout << "+---------------------v-----------v-----+" << endl;
        for (int i = 0; i < countBill; i++)
        {
            Iptr[indexList[i]]->bprint(cout);
        }
        cout << "+---------------------^-----------^-----+" << endl;
        cout << "| total: " << setw(24) << fixed << setprecision(2) << sumtotal << " |" << endl;
        cout << "^---------------------------------^" << endl;

        delete[] indexList;
    };

    int PosApp::search(int sku) const
    {
        for (int i = 0; i < nptr; i++)
        {
            if (Iptr[i]->sku() == sku)
                return i;
        }
        cout << "!!!!! Item Not Found !!!!!" << endl;
        return -1;
    }

    void titleHeader()
    {
        cout << setfill(' ') << left << setw(4) << " Row "
             << "| "
             << left << setw(7) << "SKU"
             << "| "
             << left << setw(19) << "Item Name"
             << "| "
             << left << setw(6) << "Price"
             << "|"
             << left << setw(3) << "TX"
             << "|"
             << left << setw(4) << "Qty"
             << "|"
             << right << setw(8) << "Total"
             << " | "
             << left << setw(12) << "Expiry Date"
             << "|" << endl;

        cout << setfill('-') << setw(5) << "-" << setw(9) << "|" << setw(21) << "|" << setw(8) << "|" << setw(4) << "|" << setw(5) << "|" << setw(10) << "|" << setw(14) << "|" << setfill(' ') << "|" << endl;
    }

    void footer(double amount)
    {
        cout << setw(47) << setfill(' ') << right << "Total Asset: $  "
             << "|" << right << setw(14) << setprecision(2) << fixed << setfill(' ') << amount << "|" << endl;
        cout << "-----------------------------------------------^--------------^" << endl
             << endl;
    }

    int PosApp::selectItem()
    {
        actionTitle("Item Selection by row number");
        cout << "Press <ENTER> to start....";
        cin.get();
        listItems(false);
        int num;
        bool done = true;

        cout << "Enter the row number: ";
        while (done)
        {
            cin >> num;
            if (cin.fail())
            {
                cout << "Invalid Integer, try again: ";
                cin.clear();
                cin.ignore(2000, '\n');
            }
            else if (num < 1 or num > 5)
            {
                cout << "[1<=value<=" << nptr << "], retry: ";
                cout << "Enter the row number: ";
            }
            else
            {
                done = false;
            }
        }
        return num;
    };

    void PosApp::listItems(bool printTotal)
    {
        actionTitle("Listing Items");
        double sum = 0;
        int repeat = 0;
        bool done = true;

        while (done)
        {
            for (int i = 0; i < nptr; i++)
            {
                if (i + 2 <= nptr)
                {
                    int comparison = strcmp(Iptr[i]->getName(), Iptr[i + 1]->getName());
                    if (comparison > 0)
                    {
                        Item *temp = Iptr[i];
                        Iptr[i] = Iptr[i + 1];
                        Iptr[i + 1] = temp;
                        repeat++;
                    }
                }
            }
            if (repeat == 0)
            {
                done = false;
            }
            repeat = 0;
        }

        titleHeader();

        for (int i = 0; i < nptr; i++)
        {
            Iptr[i]->displayType(POS_LIST);
            cout << setw(4) << setfill(' ') << right << i + 1 << " | ";
            Iptr[i]->write(cout);
            if (i != nptr - 1)
                cout << endl;
            sum += Iptr[i]->cost() * Iptr[i]->quantity();
        }

        cout << endl
             << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;

        if (printTotal)
            footer(sum);
    };

    void PosApp::saveRecs()
    {
        actionTitle("Saving Data");
        cout << "Goodbye!" << endl;
        ofstream output(filename);
        for (int i = 0; i < nptr; i++)
        {
            Iptr[i]->save(output);
            output.put('\n');
        }
    };

    void PosApp::loadRecs()
    {
        actionTitle("Loading Items");
        ifstream input(filename);
        if (input.fail())
        {
            ofstream output(filename);
            output.close();
            return;
        }
        else
        {
            clearItems();
            bool done = true;
            char type = '\0';

            while (done && !input.fail())
            {
                input.get(type);
                if (input.eof())
                {
                    done = false;
                    break;
                }
                if (type == 'P' || type == 'N')
                {
                    Item *item = nullptr;
                    if (type == 'P')
                    {
                        item = new Perishable();
                    }
                    else if (type == 'N')
                    {
                        item = new NonPerishable();
                    }
                    input.ignore();
                    item->load(input);
                    Iptr[nptr] = item;
                    input.ignore();
                    nptr++;
                }
            }
        }
        input.close();
    };

    void PosApp::actionTitle(const char *title) const
    {
        cout << ">>>> " << left << setw(72) << setfill('.') << title << endl;
    }

}
