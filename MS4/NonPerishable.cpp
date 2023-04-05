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
        return ostr;
    }
}