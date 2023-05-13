#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H

#include "Item.h"
#include "Date.h"

namespace sdds
{
    class Perishable : public Item
    {
        Date m_expireDate;

    public:
        Perishable();

        char itemType() const override;

        ostream &write(ostream &ostr) const override;
        ofstream &save(ofstream &ofstr) const override;
        ifstream &load(ifstream &ifstr) override;
        istream &read(istream &istr) override;
    };
}

#endif
