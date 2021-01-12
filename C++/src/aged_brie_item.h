#ifndef GILDEDROSE_AGED_BRIE_ITEM_H
#define GILDEDROSE_AGED_BRIE_ITEM_H

#include "item.h"

class AgedBrieItem : public Item
{
public:
    AgedBrieItem(int days_remaining, int quality);
    void tick() override;
};

#endif  //GILDEDROSE_AGED_BRIE_ITEM_H
