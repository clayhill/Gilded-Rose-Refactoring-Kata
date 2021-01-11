#include "GildedRose/gilded_rose.h"

#include <string>

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
        if (_quality > 0) {
            if (_days_remaining <= 0) {
                _quality -= 1;
            }
            _quality -= 1;
        }

        _days_remaining -= 1;

        return;
    }

    if (_name != kItemAgedBrie && _name != kItemBackstagePasses) {
        if (_quality > 0) {
            if (_name != kItemSulfuras) {
                _quality = _quality - 1;
            }
        }
    }
    else {
        if (_quality < 50) {
            _quality = _quality + 1;
            if (_name == kItemBackstagePasses) {
                if (_days_remaining < 11) {
                    if (_quality < 50) {
                        _quality = _quality + 1;
                    }
                }
                if (_days_remaining < 6) {
                    if (_quality < 50) {
                        _quality = _quality + 1;
                    }
                }
            }
        }
    }
    if (_name != kItemSulfuras) {
        _days_remaining = _days_remaining - 1;
    }
    if (_days_remaining < 0) {
        if (_name != kItemAgedBrie) {
            if (_name != kItemBackstagePasses) {
                if (_quality > 0) {
                    if (_name != kItemSulfuras) {
                        _quality = _quality - 1;
                    }
                }
            }
            else {
                _quality = _quality - _quality;
            }
        }
        else {
            if (_quality < 50) {
                _quality = _quality + 1;
            }
        }
    }
}

int GildedRose::days_remaining()
{
    return _days_remaining;
}

int GildedRose::quality()
{
    return _quality;
}
