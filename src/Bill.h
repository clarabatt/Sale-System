#ifndef SDDS_BILL_H
#define SDDS_BILL_H
#include <iostream>
#include "Item.h"
namespace sdds
{
    const unsigned MAX_BILL_ITEMS = 100u;
    class Bill
    {
        const Item *m_items[MAX_BILL_ITEMS]{};
        unsigned m_num = 0;
        double m_total = 0;

    public:
        void clear();
        bool add(const Item *item);
        double total() const;
        std::ostream &print(std::ostream &ostr) const;
    };
}
#endif // SDDS_BILL_H
