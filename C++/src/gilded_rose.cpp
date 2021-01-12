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
}  // namespace

GildedRose::GildedRose(const std::string &name, int days_remaining, int quality)
    : _name(name)
    , _days_remaining(days_remaining)
    , _quality(quality)
{
}

void GildedRose::tick()
{
    std::unique_ptr<Item> item{createItem()};
    item->tick();
    _days_remaining = item->days_remaining();
    _quality = item->quality();
}
std::unique_ptr<Item> GildedRose::createItem()
{
    std::unique_ptr<Item> item;

    if (_name == kItemNormal) {
        item = std::make_unique<NormalItem>(_days_remaining, _quality);
    }
    else if (_name == kItemAgedBrie) {
        item = std::make_unique<AgedBrieItem>(_days_remaining, _quality);
    }
    else if (_name == kItemSulfuras) {
        item = std::make_unique<Item>(_days_remaining, _quality);
    }
    else if (_name == kItemBackstagePasses) {
        item = std::make_unique<BackstagePassesItem>(_days_remaining, _quality);
    }
    return item;
}

int GildedRose::days_remaining()
{
    return _days_remaining;
}

int GildedRose::quality()
{
    return _quality;
}
