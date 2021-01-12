#ifndef GILDEDROSE_NORMAL_ITEM_H
#define GILDEDROSE_NORMAL_ITEM_H

#include "item.h"

class NormalItem
    : public Item
{
public:
    NormalItem(int days_remaining, int quality);
    void tick() override;
};

#endif  //GILDEDROSE_NORMAL_ITEM_H
