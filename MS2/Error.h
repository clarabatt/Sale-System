

// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 12/03/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#ifndef SDDS_ERROR_H_
#define SDDS_ERROR_H_

namespace sdds {

    class Error {
        char* error_message = nullptr;

    public:
        Error(const char* msg);
        Error(Error& newError);
        ~Error();
        Error& operator=(Error& newError);

    };

}
#endif // !SDDS_ERROR_H_

