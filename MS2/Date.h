

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

#include <iostream>
#include "Error.h"
#include "POS.h"

using namespace std;

namespace sdds {

    class Date {
        int m_year = 0, m_month = 0, m_day = 0, m_hour = 0, m_minute = 0;
        bool m_dateOnly = false;
        Error m_error;

    public:
        Date();
        Date(int y, int m, int d);
        Date(int y, int m, int d, int h, int min = -1);

        Date& dateOnly(bool value);
        void display(ostream& ostr) const;
        char* getErrorMessage() const;
        void clearError() const;

        bool operator==(const Date& right) const;
        bool operator!=(const Date& right) const;
        bool operator<(const Date& right) const;
        bool operator>(const Date& right) const;
        bool operator<=(const Date& right) const;
        bool operator>=(const Date& right) const;

        operator bool() const;


    protected:
        void setDate(int y, int m, int d);
        void setTime(int h, int m);

    };

    ostream& operator<<(ostream& ostr, const Date& right);
    istream& operator>>(istream& ostr, const Date& left);

}

#endif // !SDDS_ERROR_H_

