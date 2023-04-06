// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 06/04/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************


#ifndef SDDS_NONPERISHABLE_H
#define SDDS_NONPERISHABLE_H

#include "Date.h"
#include "Item.h"

namespace sdds
{
    class NonPerishable : public Item
    {
        Date m_exp_date;

    public:
        char itemType() const override;
        ostream &write(ostream &ostr) const override;
    };
}

#endif // MS4_NONPERISHABLE_H
