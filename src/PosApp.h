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
        int menu();
        PosApp(const char filename[]);
        void run();
        ~PosApp();

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
