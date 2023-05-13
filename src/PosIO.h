#ifndef SDDS_POSIO_H_
#define SDDS_POSIO_H_

#include <iostream>

using namespace std;

namespace sdds
{

    class PosIO
    {

    public:
        virtual ~PosIO();
        virtual ofstream &save(ofstream &ofstr) const = 0;
        virtual ostream &write(ostream &ostr) const = 0;
        virtual ifstream &load(ifstream &ifstr) = 0;
        virtual istream &read(istream &istr) = 0;
    };

    ostream &operator<<(ostream &ostr, PosIO &right);
    ofstream &operator<<(ofstream &ofstr, PosIO &right);

    istream &operator>>(istream &istr, PosIO &right);
    ifstream &operator>>(ifstream &ifstr, PosIO &right);

}

#endif // !SDDS_POSIO_H_
