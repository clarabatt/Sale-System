#include <iostream>
#include <ctime>
#include "Date.h"
#include "Error.h"
#include "POS.h"

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
        m_year = 0;
        m_month = 0;
        m_day = 0;
        m_hour = 0;
        m_minute = 0;
        m_dateOnly = true;
        m_error = new Error('Invalid Year');
    };

    void Date::setDate(int y, int m, int d) {
        if (y < MIN_YEAR or y > MAX_YEAR) {
            m_error = new Error('Invalid Year');
        } else if (m < 1 or m > 12){
            m_error = new Error('Invalid Month');
        } else if (d < 1 or d > daysOfMonth(y, m)){
            m_error = new Error('Invalid Day');
        } else {
            m_year = y;
            m_month = m;
            m_day = d;
        }
    };


    void Date::setTime(int h, int m) {
        if (h < 0 or h > 23) {
            m_error = new Error('Invalid Hour');
        } else if (m < 0 or m > 59){
            m_error = new Error('Invalid Minute');
        }else {
            m_hour = h;
            m_minute = m;
        }
    };

    Date::Date(int y, int m, int d){
        setDate(y, m, d);
        m_dateOnly = true;
    };

    Date::Date(int y, int m, int d, int h, int min){
        setDate(y, m, d);
        setTime(h, min);
        m_dateOnly = false;
    };

    Date& Date::dateOnly(bool value){
        m_dateOnly = value;
        return *this;
    };

    istream& operator>>(istream& istr, const Date& left) {

        return istr;
    };

}