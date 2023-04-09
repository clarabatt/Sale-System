// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 09/04/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#ifndef SDDS_POS_H_
#define SDDS_POS_H_

namespace sdds
{

    const int MAX_LEN_FILENAME = 255;
    const double TAX = 0.13;
    const int MAX_SKU_LEN = 7;

    const int MIN_YEAR = 2000;
    const int MAX_YEAR = 2030;

    const int MAX_STOCK_NUMBER = 99;
    const int MAX_NO_ITEMS = 200;

    const int MAX_NAME_LEN = 40;

    const int POS_LIST = 1;
    const int POS_FORM = 2;

    const char *const ERROR_POS_SKU = "SKU too long";
    const char *const ERROR_POS_NAME = "Item name too long";
    const char *const ERROR_POS_PRICE = "Invalid price value";
    const char *const ERROR_POS_TAX = "Invalid tax status";
    const char *const ERROR_POS_QTY = "Invalid quantity value";
    const char *const ERROR_POS_STOCK = "Item out of stock";
    const char *const ERROR_POS_EMPTY = "Invalid Empty Item";

}
#endif // !SDDS_POS_H_
