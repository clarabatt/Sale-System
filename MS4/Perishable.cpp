//
// Created by Clara Battesini on 2023-04-03.
//

#include <iostream>
#include <fstream>
#include "Perishable.h"

using namespace std;

namespace sdds
{
    Perishable::Perishable() {
        Date m_expireDate;
        m_expireDate.dateOnly(true);
    }

    char Perishable::itemType() const {
        return 'P';
    }


    istream& Perishable::read(istream &istr){
        if (istr.fail() || Item::m_error){
            return istr;
        } else {
            Date new_date;
            new_date.dateOnly(true);
            cout << "Expiry date(YYYY/MM/DD)" << endl << "> ";
            istr >> new_date;

            if (new_date){
                m_expireDate = new_date;
            } else {
                Item::m_error = new_date.getErrorMessage();
            }
        }
        return istr;
    };

    ostream& Perishable::write(ostream &ostr) const {
        Item::write(ostr);

        if (!Item::m_error && !ostr.fail()){
            if (Item::m_displayType == POS_LIST) {
                ostr << " " << m_expireDate << " |";
            }
            else{
                ostr << "Expiry date: " << m_expireDate << endl << "=============^" << endl;
            }
        }
        return ostr;
    }

    ifstream& Perishable::load(ifstream& ifstr){
        Item::load(ifstr);

        if (!Item::m_error && !ifstr.fail()){
            Date new_date;
            new_date.dateOnly(true);
            ifstr.ignore(1);

//            ifstr.getline(new_date, 9, ',');
            ifstr >> new_date;

            if (new_date){
                m_expireDate = new_date;
            } else {
                Item::m_error = new_date.getErrorMessage();
            }
        }
        return ifstr;
    };

    ofstream& Perishable::save(ofstream &ofstr) const{
        Item::save(ofstr);

        if (!Item::m_error && !ofstr.fail()){
            ofstr << "," << m_expireDate;
        }
        return ofstr;

    };
}