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