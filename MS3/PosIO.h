// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 22/03/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#ifndef SDDS_POSIO_H_
#define SDDS_POSIO_H_

#include <iostream>

using namespace std;

namespace sdds {

    class PosIO {
        char* error_message = nullptr;

    public:
        PosIO();
        virtual ~PosIO();
        virtual ostream& write() = 0;
        virtual istream& read(istream& istr) = 0;
        virtual ofstream& save(ofstream& ofstr) = 0;
        virtual ifstream& load(ifstream& ifstr) = 0;
    };

    ostream& operator<<(ostream& ostr, PosIO& right);
    ofstream& operator<<(ofstream& ofstr, PosIO& right);

    istream& operator>>(istream& ifstr, PosIO& right);
    ifstream& operator>>(ifstream& ifstr, PosIO& right);

}

#endif // !SDDS_POSIO_H_

