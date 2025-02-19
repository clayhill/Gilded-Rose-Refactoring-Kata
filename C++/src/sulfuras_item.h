#ifndef SULFURAS_H
#define SULFURAS_H

#include "item.h"

class SulfurasItem : public Item
{
public:
    SulfurasItem(int days_remaining, int quality);
    void tick();
};

#endif  //SULFURAS_H
