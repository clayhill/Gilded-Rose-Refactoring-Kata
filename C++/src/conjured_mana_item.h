#ifndef GILDEDROSE_CONJURED_MANA_ITEM_H
#define GILDEDROSE_CONJURED_MANA_ITEM_H

#include "item.h"

class ConjuredManaItem
    : public Item
{
public:
    ConjuredManaItem(int days_remaining, int quality);
    void tick() override;
};

#endif  //GILDEDROSE_CONJURED_MANA_ITEM_H
