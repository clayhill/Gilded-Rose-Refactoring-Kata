#ifndef BACKSTAGE_PASS_H
#define BACKSTAGE_PASS_H

#include "item.h"

class BackstagePass : public Item
{
public:
    BackstagePass(int days_remaining, int quality);
    void tick();
};

#endif  //BACKSTAGE_PASS_H
