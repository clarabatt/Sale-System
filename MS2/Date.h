// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 22/03/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_

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
        Date(int y, int m, int d, int h, int min = 0);

        Date& dateOnly(bool value);
        void display(ostream& ostr) const;
        char* getErrorMessage() const;
        void clearError();
        const Error& error() const;

        bool operator==(const Date& right) const;
        bool operator!=(const Date& right) const;
        bool operator<(const Date& right) const;
        bool operator>(const Date& right) const;
        bool operator<=(const Date& right) const;
        bool operator>=(const Date& right) const;

        operator bool() const;

        void setDate(int y, int m, int d, bool val);
        void setTime(int h, int m, bool val);
        void setError(const char * str);

    };

    ostream& operator<<(ostream& ostr, Date& right);
    istream& operator>>(istream& istr, Date& left);

}

#endif // !SDDS_DATE_H_

