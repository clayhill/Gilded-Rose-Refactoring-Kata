#ifndef GILDEDROSE_BACKSTAGE_PASSES_ITEM_H
#define GILDEDROSE_BACKSTAGE_PASSES_ITEM_H

#include "item.h"

class BackstagePassesItem : public Item
{
public:
    BackstagePassesItem(int days_remaining, int quality);
    void tick() override;
};

#endif  //GILDEDROSE_BACKSTAGE_PASSES_ITEM_H
