// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 22/03/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#include <iostream>
#include <cstring>
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

    void Item::setName(const char *newName){
        if (newName != nullptr and *newName != '\0') {
            if (m_name != nullptr) {
                delete [] m_name;
                m_name = nullptr;
            }
            int len = strlen(newName);
            m_name = new char[len+1];
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
        return strcmp(obj.m_sku, m_sku) == 1;
    };

    bool Item::operator==(const char * str) const{
        return strcmp(str, m_sku) == 1;
    };

    bool Item::operator>(const Item &obj) const
    {
        return strcmp(obj.m_name, m_name) < 0;
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

    ostream &Item::write(ostream &os) const {
        if (m_error){
            os << m_error.getMessage();
        }
        else {
            if (m_displayType == POS_FORM)
            {
                os << "=============v" << endl;
                os << "Name:        " << m_name << endl;
                os << "Sku:         " << m_sku << endl;
                os << "Price:       " << m_price << endl;
                if (m_taxed)
                {
                    os << "Price + tax: " << m_price * (1 + TAX) << endl;
                }
                else
                {
                    os << "Price + tax: N/A" << endl;
                }
                os << "Stock Qty:   " << m_quantity << endl;
                os << "=============v" << endl;
            }
            else
            {
                string name = m_name;
                if (name.length() > 20)
                {
                    name = name.substr(0, 20);
                }
                os << setw(4) << left << m_sku << " |";
                os << setw(20) << left << name << " |";
                os << setw(7) << right << fixed << setprecision(2) << m_price << " |";
                os << (m_taxed ? " X |" : "   |");
                os << setw(4) << right << m_quantity << " |";
                if (m_taxed)
                {
                    os << setw(9) << right << fixed << setprecision(2) << m_price * (1 + TAX) * m_quantity;
                }
                else
                {
                    os << setw(9) << right << fixed << setprecision(2) << m_price * m_quantity;
                }
                os << "|" << endl;
            }
        }
        return os;
    };

    ofstream &Item::save(ofstream& ofstr) const {
//        if (!ofstr) {
//            std::cerr << "Error: file is not open" << endl;
//        } else {
//            cout << m_displayType << ",";
//            ofstr >> m_sku << "," << m_name << "," << m_price << "," << m_taxed << "," << m_quantity << ",";
//        }
        return ofstr;
    }

    ifstream& Item::load(ifstream &ifstr) {
        return ifstr;
    };
    istream& Item::read(istream &istr) {
        return istr;
    };

    ostream& Item::bprint(ostream &ostr) const{
        return ostr;
    };

    ostream &operator<<(ostream &ostr, const Item &obj){
        obj.write(ostr);
        return ostr;
    };
    istream &operator>>(istream &istr, Item &obj){
        obj.read(istr);
        return istr;
    };
    ofstream &operator<<(ofstream &ofstr, const Item &obj){
        obj.save(ofstr);
        return ofstr;
    };
    ifstream &operator>>(ifstream &ifstr, Item &obj){
        obj.load(ifstr);
        return ifstr;
    };
}