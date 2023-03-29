// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 22/03/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_

#include <iostream>
#include "POS.h"
#include "Error.h"

using namespace std;

namespace sdds
{

    class Item
    {
        char m_sku[MAX_SKU_LEN] = {'/0'};
        char *m_name[MAX_NAME_LEN];
        double m_price = 0.0;
        bool m_taxed = false;
        int m_quantity = 0;

    protected:
        int m_displayType = 0;
        Error m_error;

    public:
        Item();
        Item(const Item &copyItem);
        Item &operator=(const Item &copyItem);
        virtual ~Item();

        bool operator==(const char *sku) const;
        bool operator>(const Item &I) const;
        int operator+=(int quantity);
        int operator-=(int quantity);
        operator bool() const;

        Item &displayType() const;
        double cost() const;
        int quantity() const;
        Item &clear();

        virtual void write() = 0;
        virtual void save() = 0;
        virtual void read() = 0;
        virtual void load() = 0;
        virtual void billPrint() = 0;
    };

    ostream &operator<<(ostream &ostr, const Item &Item);
    istream &operator>>(istream &istr, Item &Item);
    double operator+=(double &d, const Item &Item);

}

#endif // !SDDS_ITEM_H_
