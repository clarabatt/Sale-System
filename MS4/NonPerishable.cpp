// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 06/04/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#include <iostream>
#include "NonPerishable.h"

using namespace std;

namespace sdds
{
    char NonPerishable::itemType() const {
        return 'N';
    }

    ostream& NonPerishable::write(ostream &ostr) const {
        Item::write(ostr);
        if (!Item::m_error){
            if (Item::m_displayType == POS_LIST) {
                ostr << "     N / A   |";
            }
            else{
                ostr << "=============^" << endl;
            }
        }
        ostr << left;
        return ostr;
    }
}