#include "GildedRose/gilded_rose.h"

#include <string>

GildedRose::GildedRose(const std::string &name, int days_remaining, int quality)
    : _name(name)
    , _days_remaining(days_remaining)
    , _quality(quality)
{
}

void GildedRose::tick()
{
    if (_name != "Aged Brie" && _name != "Backstage passes to a TAFKAL80ETC concert") {
        if (_quality > 0) {
            if (_name != "Sulfuras, Hand of Ragnaros") {
                _quality = _quality - 1;
            }
        }
    }
    else {
        if (_quality < 50) {
            _quality = _quality + 1;
            if (_name == "Backstage passes to a TAFKAL80ETC concert") {
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
    if (_name != "Sulfuras, Hand of Ragnaros") {
        _days_remaining = _days_remaining - 1;
    }
    if (_days_remaining < 0) {
        if (_name != "Aged Brie") {
            if (_name != "Backstage passes to a TAFKAL80ETC concert") {
                if (_quality > 0) {
                    if (_name != "Sulfuras, Hand of Ragnaros") {
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
