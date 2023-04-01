
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include "Item.h"

using namespace std;

namespace sdds
{
    Item::Item() : m_sku{}, m_name(nullptr), m_price(0.0), m_taxed(false), m_quantity(0), m_displayType(POS_LIST){};

    Item::Item(const Item &obj)
    {
        *this = obj;
    };

    void Item::setName(const char *newName)
    {
        if (newName != nullptr and *newName != '\0')
        {
            if (m_name != nullptr)
            {
                delete[] m_name;
                m_name = nullptr;
            }
            int len = strlen(newName);
            m_name = new char[len + 1];
            strcpy(m_name, newName);
        }
    };

    Item &Item::operator=(const Item &other)
    {
        if (this != &other)
        {
            strcpy(m_sku, other.m_sku);
            m_price = other.m_price;
            m_taxed = other.m_taxed;
            m_quantity = other.m_quantity;
            m_displayType = other.m_displayType;
            m_error = other.m_error.getMessage();
            setName(other.m_name);
        }
        return *this;
    }

    Item::~Item()
    {
        delete[] m_name;
    }

    bool Item::operator==(const Item &obj) const
    {
        return strcmp(obj.m_sku, m_sku) == 0;
    };

    bool Item::operator==(const char *str) const
    {
        return strcmp(str, m_sku) == 0;
    };

    bool Item::operator>(const Item &obj) const
    {
        return strcmp(obj.m_name, m_name) > 0;
    };

    int Item::operator+=(int quantity)
    {
        int sum = m_quantity + quantity;
        if (sum > MAX_STOCK_NUMBER)
        {
            sum = MAX_STOCK_NUMBER;
            m_error = ERROR_POS_QTY;
        }
        return m_quantity = sum;
    };

    int Item::operator-=(int quantity)
    {
        int sum = m_quantity - quantity;
        if (sum < 0)
        {
            sum = 0;
            m_error = ERROR_POS_STOCK;
        }
        return m_quantity = sum;
    };

    Item::operator bool() const
    {
        return !m_error;
    };

    double operator+=(double &num, const Item &obj)
    {
        double sum = num + obj.cost() * obj.quantity();
        return num = sum;
    };

    Item &Item::displayType(int type)
    {
        m_displayType = type;
        return *this;
    };

    double Item::cost() const
    {
        return m_taxed ? m_price + (m_price * TAX) : m_price;
    };

    int Item::quantity() const
    {
        return m_quantity;
    };

    Item &Item::clear()
    {
        m_error.clear();
        return *this;
    };

    ostream &Item::write(ostream &ostr) const
    {
        if (m_error)
        {
            ostr << m_error.getMessage();
        }
        else
        {
            char *name = {};
            if (m_name != nullptr)
            {
                strncpy(name, m_name, 20);
            }
            if (m_displayType == POS_LIST)
            {
                ostr << setw(4) << left << m_sku << " |";
                ostr << setw(20) << left << name << " |";
                ostr << setw(7) << right << fixed << setprecision(2) << m_price << " |";
                ostr << (m_taxed ? " X |" : "   |");
                ostr << setw(4) << right << m_quantity << " |";
                if (m_taxed)
                {
                    ostr << setw(9) << right << fixed << setprecision(2) << m_price * (1 + TAX) * m_quantity;
                }
                else
                {
                    ostr << setw(9) << right << fixed << setprecision(2) << m_price * m_quantity;
                }
                ostr << "|" << endl;
            }
            else
            {
                ostr << "=============v" << endl;
                ostr << "Name:        " << name << endl;
                ostr << "Sku:         " << m_sku << endl;
                ostr << "Price:       " << m_price << endl;
                if (m_taxed)
                {
                    ostr << "Price + tax: " << m_price * (1 + TAX) << endl;
                }
                else
                {
                    ostr << "Price + tax: N/A" << endl;
                }
                ostr << "Stock Qty:   " << m_quantity << endl;
                ostr << "=============v" << endl;
            }
        }
        return ostr;
    };

    ofstream &Item::save(ofstream &ofstr) const
    {

        return ofstr;
    }

    ifstream &Item::load(ifstream &ifstr)
    {
        m_error.clear();

        char *sku;
        char *name;
        double price;
        bool taxed;
        int quantity;

        bool proceed = true;

        ifstr.getline(sku, strlen(sku), ',');
        if (ifstr.fail() and sku[0] == '\0')
        {
            m_error = ERROR_POS_EMPTY;
            proceed = false;
        }
        else if (strlen(sku) > MAX_SKU_LEN)
        {
            m_error = ERROR_POS_SKU;
            proceed = false;
        }

        ifstr.ignore();
        ifstr.getline(name, strlen(name), ',');
        if (ifstr.fail() and name[0] == '\0')
        {
            m_error = ERROR_POS_EMPTY;
            proceed = false;
        }
        else if (strlen(name) > MAX_NAME_LEN)
        {
            m_error = ERROR_POS_NAME;
            proceed = false;
        }

        ifstr.ignore();
        ifstr >> price;
        if (ifstr.fail() and price == 0)
        {
            m_error = ERROR_POS_PRICE;
            proceed = false;
        }

        ifstr.ignore();
        ifstr >> taxed;
        if (ifstr.fail())
        {
            m_error = ERROR_POS_TAX;
            proceed = false;
        }

        ifstr.ignore();
        ifstr >> quantity;
        if (ifstr.fail() || quantity > MAX_NO_ITEMS || quantity < 0)
        {
            m_error = ERROR_POS_QTY;
            proceed = false;
        }

        if (proceed)
        {
            strcpy(m_sku, sku);
            setName(name);
            m_price = price;
            m_taxed = taxed;
            m_quantity = quantity;
        }

        return ifstr;
    };

    istream &Item::read(istream &istr)
    {
        char sku[MAX_SKU_LEN + 1];
        char name[MAX_NAME_LEN + 1] = {0};
        double price;
        char taxed = '\0';
        int quantity;

        cout << "Sku" << endl
             << "> ";
        istr >> sku;
        while (istr.fail() || strlen(sku) > MAX_SKU_LEN)
        {
            if (strlen(sku) > MAX_SKU_LEN)
                cout << ERROR_POS_SKU;
            else
                cout << ERROR_POS_EMPTY;
            cout << endl
                 << "> ";
            istr.clear();
            istr.ignore(1000, '\n');
            istr >> sku;
        }

        cout << "Name" << endl
             << "> ";
        istr.ignore();
        istr.getline(name, MAX_NAME_LEN);
        while (istr.fail() || strlen(name) > MAX_NAME_LEN)
        {
            cout << ERROR_POS_NAME;
            cout << endl
                 << "> ";
            istr.clear();
            istr.ignore(1000, '\n');
            istr >> name;
        }

        cout << "Price" << endl
             << "> ";
        istr >> price;
        while (istr.fail() || price < 0)
        {
            cout << ERROR_POS_PRICE;
            cout << endl
                 << "> ";
            istr.clear();
            istr.ignore(1000, '\n');
            istr >> price;
        }

        cout << "Taxed?" << endl
             << "> ";
        istr >> taxed;
        while (istr.fail() || (taxed != 'y' && taxed != 'n'))
        {
            cout << "Only 'y' and 'n' are acceptable: ";
            istr.clear();
            istr.ignore(1000, '\n');
            istr >> taxed;
        }

        cout << "Quantity" << endl
             << "> ";
        istr >> quantity;
        while (istr.fail() || quantity > MAX_STOCK_NUMBER || quantity <= 0)
        {
            cout << ERROR_POS_QTY << endl
                 << "> ";
            istr.clear();
            istr.ignore(1000, '\n');
            istr >> quantity;
        }

        strcpy(m_sku, sku);
        setName(name);
        m_price = price;
        m_taxed = taxed == 'y';
        m_quantity = quantity;

        return istr;
    };

    ostream &Item::bprint(ostream &ostr) const
    {
        return ostr;
    };

    ostream &operator<<(ostream &ostr, const Item &obj)
    {
        obj.write(ostr);
        return ostr;
    };
    istream &operator>>(istream &istr, Item &obj)
    {
        obj.read(istr);
        return istr;
    };
    ofstream &operator<<(ofstream &ofstr, const Item &obj)
    {
        obj.save(ofstr);
        return ofstr;
    };
    ifstream &operator>>(ifstream &ifstr, Item &obj)
    {
        obj.load(ifstr);
        return ifstr;
    };
}