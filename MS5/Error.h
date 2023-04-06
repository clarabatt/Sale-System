// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 22/03/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#ifndef SDDS_ERROR_H_
#define SDDS_ERROR_H_

#include <iostream>

using namespace std;

namespace sdds {

    class Error {
        char* error_message = nullptr;

    public:
        Error();
        Error(const char* msg);
        Error(Error& copyError);
        ~Error();
        Error& operator=(Error& copyError);
        operator bool() const;
        char* getMessage() const;
        Error& clear();
        Error& operator=(const char* msg);

    };

    ostream& operator<<(ostream& ostr, const Error& right);

}

#endif // !SDDS_ERROR_H_

