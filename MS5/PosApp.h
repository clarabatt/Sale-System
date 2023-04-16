// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 09/04/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#ifndef SDDS_POSAPPCLASS_H_
#define SDDS_POSAPPCLASS_H_

#include "POS.h"

namespace sdds
{

    class Item;

    class PosApp
    {
        char filename[MAX_LEN_FILENAME];
        Item *Iptr[MAX_NO_ITEMS] = {nullptr};
        int nptr = 0;

    public:
        // IMPLEMENTED
        int menu();
        PosApp(const char filename[]);
        void run();
        ~PosApp();

        // Deleting copy constructor and assignment operators
        PosApp(const PosApp &) = delete;
        PosApp &operator=(const PosApp &) = delete;

        int selectItem();
        void addItem();
        void removeItem();
        void stockItem();
        void listItems(bool printTotal = true);
        void clearItems();
        void POS();
        int search(int sku) const;
        void saveRecs();
        void loadRecs();
        void actionTitle(const char *title) const;
    };

}
#endif // !SDDS_POSAPPCLASS_H_
