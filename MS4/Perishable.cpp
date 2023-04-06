//
// Created by Clara Battesini on 2023-04-03.
//

#include <iostream>
#include <fstream>
#include "Perishable.h"

using namespace std;

namespace sdds
{
    Perishable::Perishable() {}

    char Perishable::itemType() const {
        return 'P';
    }


    istream& Perishable::read(istream &istr){
        Item::read(istr);
        Item::clear();
        if (istr.fail()){
            return istr;
        } else {
            Date new_date(2050, 10, 10);
            cout << "Expiry date (YYYY/MM/DD)" << endl << "> ";
            istr >> new_date;

            if (new_date){
                m_expireDate = new_date;
                m_expireDate.dateOnly(true);
            } else {
                Item::m_error = new_date.getErrorMessage();
            }
        }
        return istr;
    };

    ostream& Perishable::write(ostream &ostr) const {
        Item::write(ostr);

        if (!ostr.fail()){
            if (Item::m_displayType == POS_LIST) {
                ostr << " ";
                m_expireDate.display(ostr);
                ostr << " |";
            }
            else{
                ostr << "Expiry date: ";
                ostr << right;
                m_expireDate.display(ostr);
                ostr << endl << "=============^" << endl;
            }
        }
        ostr << left;
        return ostr;
    }

    ifstream& Perishable::load(ifstream& ifstr){
        Item::load(ifstr);

        if (!ifstr.fail()){

            char c = ifstr.get();

            while (c != ','){
                ifstr.seekg(-2, ios::cur);
                c = ifstr.get();
            }

            Date new_date(2050, 10, 10);
            ifstr >> new_date;

            if (new_date){
                m_expireDate = new_date;
                m_expireDate.dateOnly(true);
            } else {
                Item::m_error = new_date.getErrorMessage();
            }
        }
        return ifstr;
    };

    ofstream& Perishable::save(ofstream &ofstr) const{
        Item::save(ofstr);

        if (!ofstr.fail()){
            ofstr << ",";
            m_expireDate.display(ofstr);
        }
        return ofstr;

    };
}