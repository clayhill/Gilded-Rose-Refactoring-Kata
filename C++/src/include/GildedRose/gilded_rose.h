#ifndef GILDEDROSE_GILDED_ROSE_H
#define GILDEDROSE_GILDED_ROSE_H

#include <memory>
#include <string>

#include "../../item.h"

class GildedRose
{
public:
    GildedRose(const std::string &name, int days_remaining, int quality);
    void tick();
    int days_remaining();
    int quality();

private:
    std::unique_ptr<Item> _item{};
};

#endif  //GILDEDROSE_GILDED_ROSE_H
