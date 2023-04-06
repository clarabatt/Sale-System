// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 22/03/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#include <iostream>
#include <ctime>
#include "Date.h"
#include "iomanip"

using namespace std;

namespace sdds {

    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly) {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;
        if(dateOnly) {
            hour = min = 0;
        } else {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }

    int uniqueDateValue(int year, int mon, int day, int hour, int min) {
        return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
    }

    int daysOfMonth(int year, int month){
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = month >= 1 && month <= 12 ? month : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    Date::Date(){
        getSystemDate(m_year, m_month, m_day, m_hour, m_minute, false);
        m_dateOnly = true;
    };

    void Date::setDate(int y, int m, int d, bool val) {
        if (val) {
            if (y < MIN_YEAR or y > MAX_YEAR) {
                m_error = "Invalid Year";
            } else if (m < 1 or m > 12) {
                m_error = "Invalid Month";
            } else if (d < 1 or d > daysOfMonth(y, m)) {
                m_error = "Invalid Day";
            }
        }
        m_year = y;
        m_month = m;
        m_day = d;
    };

    void Date::setError(const char * str) {
        m_error = str;
    };


    void Date::setTime(int h, int m, bool val) {
        if (val) {
            if (h < 0 or h > 23) {
                m_error = "Invalid Hour";
            } else if (m < 0 or m > 59) {
                m_error = "Invalid Minute";
            }
        }
            m_hour = h;
            m_minute = m;
    };

    Date::Date(int y, int m, int d){
        setDate(y, m, d, true);
        m_dateOnly = true;
    };

    Date::Date(int y, int m, int d, int h, int min){
        setDate(y, m, d, true);
        setTime(h, min, true);
        if (h != 0 and min != 0)
            m_dateOnly = false;
        else
            m_dateOnly = true;
    };

    Date& Date::dateOnly(bool value){
        m_dateOnly = value;
        return *this;
    };

    void Date::display(ostream& ostr) const{
        ostr << m_year << "/" << setw(2) << setfill('0')
        << m_month << "/" << setw(2) << setfill('0') << m_day;
        if (!m_dateOnly)
            ostr << ", " << setw(2) << setfill('0') << m_hour << ":" << setw(2) << setfill('0') << m_minute;
        ostr << setfill(' ');
    };

    char* Date::getErrorMessage() const{
        return m_error.getMessage();
    };

    void Date::clearError() {
        m_error.clear();
    };

    const Error& Date::error() const{
        return m_error;
    };

    ostream& operator<<(ostream& ostr, Date& left) {
//        left.clearError();
        if (left.getErrorMessage()) {
            ostr << left.getErrorMessage() << "(";
            left.display(ostr);
            ostr << ")";
        } else {
            left.display(ostr);
        }
        return ostr;
    };

    istream& operator>>(istream& istr, Date& left) {
        left.clearError();
        int y = 0, m = 0, d = 0, h = 0, min = 0;
        bool proceed = true;

        istr >> y;
        if (istr.fail() and y == 0 ) {
            left.setError("Cannot read year entry");
            proceed = false;
        } else if (y < MIN_YEAR or y > MAX_YEAR) {
            left.setError("Invalid Year");
        }

        istr.ignore();
        istr >> m;
        if (istr.fail() and proceed and m == 0) {
            left.setError("Cannot read month entry");
            proceed = false;
        } else if ((m < 1 or m > 12) and proceed) {
            left.setError("Invalid Month");
            proceed = false;
        }

        istr.ignore();
        istr >> d;
        if (istr.fail() and proceed and d == 0) {
            left.setError("Cannot read day entry");
            proceed = false;
        } else if (proceed and (d < 1 or d > daysOfMonth(y, m))) {
            left.setError("Invalid Day");
        }

        if (istr.peek() != '\n') {
            istr.ignore();
            istr >> h;

            if (istr.fail() and proceed and h == 0) {
                left.setError("Cannot read hour entry");
                proceed = false;
            } else if (h < 0 or h > 23) {
                left.setError("Invalid Hour");
            }
            istr.ignore();
            istr >> min;
            if (istr.fail() and proceed and min == 0) {
                left.setError("Cannot read minute entry");
                proceed = false;
            } else if (min < 0 or min > 59) {
                left.setError("Invlid Minute");
            }
        }
//        if (h == 0 and min == 0) left.dateOnly(true);
        left.setDate(y, m, d, false);
        left.setTime(h, min, false);

        return istr;
    };



    bool Date::operator==(const Date& right) const{
        int rightVal = uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute);
        int leftVal = uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute);
        return(rightVal == leftVal);
    };
    bool Date::operator!=(const Date& right) const{
        int rightVal = uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute);
        int leftVal = uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute);
        return(rightVal != leftVal);
    };
    bool Date::operator<(const Date& right) const{
        int rightVal = uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute);
        int leftVal = uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute);
        return(leftVal < rightVal);
    };
    bool Date::operator>(const Date& right) const{
        int rightVal = uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute);
        int leftVal = uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute);
        return(leftVal > rightVal);
    };
    bool Date::operator<=(const Date& right) const{
        int rightVal = uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute);
        int leftVal = uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute);
        return(leftVal <= rightVal);
    };
    bool Date::operator>=(const Date& right) const{
        int rightVal = uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute);
        int leftVal = uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute);
        return(leftVal >= rightVal);
    };

    Date::operator bool() const {
        return !m_error;
    };
}