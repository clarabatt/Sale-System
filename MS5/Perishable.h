// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 06/04/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************


#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H

#include "Item.h"
#include "Date.h"

namespace sdds {
    class Perishable : public Item {
        Date m_expireDate;

    public:
        Perishable();

        char itemType() const override;

        ostream &write(ostream &ostr) const override;
        ofstream &save(ofstream &ofstr) const override;
        ifstream &load(ifstream &ifstr) override;
        istream &read(istream &istr) override;
    };
}

#endif //MS4_PERISHABLE_H
