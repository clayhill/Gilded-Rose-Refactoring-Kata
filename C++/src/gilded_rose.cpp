#include "GildedRose/gilded_rose.h"

#include <memory>
#include <string>

#include "aged_brie_item.h"
#include "backstage_passes_item.h"
#include "normal_item.h"

namespace
{
const char *const kItemNormal = "Normal Item";
const char *const kItemAgedBrie = "Aged Brie";
const char *const kItemBackstagePasses = "Backstage passes to a TAFKAL80ETC concert";
const char *const kItemSulfuras = "Sulfuras, Hand of Ragnaros";

std::unique_ptr<Item> createItem(const std::string &name, int days_remaining, int quality)
{
    std::unique_ptr<Item> item;

    if (name == kItemNormal) {
        item = std::make_unique<NormalItem>(days_remaining, quality);
    }
    else if (name == kItemAgedBrie) {
        item = std::make_unique<AgedBrieItem>(days_remaining, quality);
    }
    else if (name == kItemSulfuras) {
        item = std::make_unique<Item>(days_remaining, quality);
    }
    else if (name == kItemBackstagePasses) {
        item = std::make_unique<BackstagePassesItem>(days_remaining, quality);
    }
    return item;
}
}  // namespace

GildedRose::GildedRose(const std::string &name, int days_remaining, int quality)
    : _name(name)
    , _days_remaining(days_remaining)
    , _quality(quality)
{
}

void GildedRose::tick()
{
    std::unique_ptr<Item> item{createItem(_name, _days_remaining, _quality)};
    item->tick();
    _days_remaining = item->days_remaining();
    _quality = item->quality();
}

int GildedRose::days_remaining()
{
    return _days_remaining;
}

int GildedRose::quality()
{
    return _quality;
}
