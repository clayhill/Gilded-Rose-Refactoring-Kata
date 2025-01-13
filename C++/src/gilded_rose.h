#ifndef GILDEDROSE_GILDED_ROSE_H
#define GILDEDROSE_GILDED_ROSE_H

#include <memory>
#include <string>

#include "aged_brie_item.h"
#include "backstage_pass.h"
#include "normal_item.h"
#include "sulfuras_item.h"

class GildedRose
{
public:
    GildedRose(const std::string &name, int days_remaining, int quality);
    void normal_tick();
    void aged_brie_tick();
    void sulfuras_tick();
    void backstage_pass_tick();
    void tick();
    int days_remaining() const;
    int quality() const;

private:
    std::unique_ptr<NormalItem> _normal_item;
    std::unique_ptr<AgedBrieItem> _aged_brie_item;
    std::unique_ptr<SulfurasItem> _sulfuras_item;
    std::unique_ptr<BackstagePass> _backstage_pass_item;
    std::string _name;
    int _days_remaining;
    int _quality;
};

#endif  //GILDEDROSE_GILDED_ROSE_H
