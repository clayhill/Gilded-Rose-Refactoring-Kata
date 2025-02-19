#ifndef AGED_BRIE_ITEM_H
#define AGED_BRIE_ITEM_H

#include "item.h"

class AgedBrieItem : public Item
{
public:
    AgedBrieItem(int days_remaining, int quality);
    void tick();
};

#endif  //AGED_BRIE_ITEM_H
