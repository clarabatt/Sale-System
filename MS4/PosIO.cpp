// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 02/04/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#include <iostream>
#include <cstring>
#include "PosIO.h"

using namespace std;

namespace sdds
{
    PosIO::~PosIO()
    {
    }

    ostream &operator<<(ostream &ostr, PosIO &right)
    {
        right.write(ostr);
        return ostr;
    };
    ofstream &operator<<(ofstream &ofstr, PosIO &right)
    {
        right.save(ofstr);
        return ofstr;
    };

    istream &operator>>(istream &istr, PosIO &right)
    {
        right.read(istr);
        return istr;
    };
    ifstream &operator>>(ifstream &ifstr, PosIO &right)
    {
        right.load(ifstr);
        return ifstr;
    };

}