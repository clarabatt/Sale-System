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
#include "PosIO.h"

using namespace std;

namespace sdds
{

    class Item : public PosIO
    {
        char m_sku[MAX_SKU_LEN];
        char *m_name;
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

        bool operator==(const Item &I) const;
        bool operator==(const char *str) const;
        bool operator>(const Item &I) const;
        int operator+=(int quantity);
        int operator-=(int quantity);
        operator bool() const;

        virtual char itemType() const = 0;
        Item &displayType(int type);
        double cost() const;
        int quantity() const;
        int sku() const;
        Item &clear();
        char *getName() const;

        ostream &write(ostream &ostr) const override;
        ofstream &save(std::ofstream &ofstr) const override;
        ifstream &load(std::ifstream &ifstr) override;
        istream &read(std::istream &istr) override;

        void setName(const char *newName);
        ostream &bprint(ostream &ostr) const;
    };

    ostream &operator<<(ostream &ostr, const Item &Item);
    istream &operator>>(istream &istr, Item &Item);
    ofstream &operator<<(ofstream &ofstr, const Item &Item);
    ifstream &operator>>(ifstream &ifstr, Item &Item);
    double operator+=(double &d, const Item &Item);

}

#endif // !SDDS_ITEM_H_
