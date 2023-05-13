#ifndef SDDS_NONPERISHABLE_H
#define SDDS_NONPERISHABLE_H

#include "Date.h"
#include "Item.h"

namespace sdds
{
    class NonPerishable : public Item
    {
        Date m_exp_date;

    public:
        char itemType() const override;
        ostream &write(ostream &ostr) const override;
    };
}

#endif
