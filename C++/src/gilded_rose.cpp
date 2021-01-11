#include "GildedRose/gilded_rose.h"

#include <string>

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
    if (_name == kItemNormal) {
        NormalItem item(_days_remaining, _quality);
        item.tick();
        _days_remaining = item.days_remaining();
        _quality = item.quality();
        return;
    }

    if (_name == kItemAgedBrie) {
        handleItemAgedBrie();
        return;
    }

    if (_name == kItemSulfuras) {
        return;
    }

    if (_name == kItemBackstagePasses) {
        handleItemBackstagePasses();
        return;
    }
}
void GildedRose::handleItemBackstagePasses()
{
    if (_quality < 50) {
        if (_days_remaining <= 10) {
            if (_days_remaining <= 5) {
                _quality += 1;
            }

            _quality += 1;
        }

        _quality += 1;
    }

    if (_days_remaining <= 0) {
        _quality = 0;
    }

    _days_remaining -= 1;
}
void GildedRose::handleItemAgedBrie()
{
    if (_quality < 50) {
        if (_quality < 49) {
            _quality += 1;
        }

        if (_days_remaining <= 0) {
            _quality += 1;
        }
    }

    _days_remaining -= 1;
}

int GildedRose::days_remaining()
{
    return _days_remaining;
}

int GildedRose::quality()
{
    return _quality;
}
