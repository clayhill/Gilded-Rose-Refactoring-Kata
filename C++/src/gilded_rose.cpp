#include "gilded_rose.h"

#include <string>

GildedRose::GildedRose(const std::string &name, int days_remaining, int quality)
    : _name(name)
    , _days_remaining(days_remaining)
    , _quality(quality)
{
}

void GildedRose::tick()
{
    if (_name == "Normal Item") {
        normal_tick();
    }
    else if (_name == "Aged Brie") {
        aged_brie_tick();
    }
    else if (_name == "Sulfuras, Hand of Ragnaros") {
        sulfuras_tick();
    }
    else if (_name == "Backstage passes to a TAFKAL80ETC concert") {
        backstage_pass_tick();
    }
}
void GildedRose::normal_tick()
{
    _days_remaining--;

    if (_quality == 0) {
        return;
    }

    _quality--;

    if (_days_remaining <= 0) {
        _quality--;
    }
}
void GildedRose::aged_brie_tick()
{
    _days_remaining--;

    if (_quality == 50) {
        return;
    }

    _quality++;

    if (_days_remaining <= 0 && _quality < 50) {
        _quality++;
    }
}
void GildedRose::sulfuras_tick()
{
}
void GildedRose::backstage_pass_tick()
{
    _days_remaining--;

    if (_quality == 50) {
        return;
    }

    if (_days_remaining < 0) {
        _quality = 0;
        return;
    }

    _quality++;

    if (_days_remaining < 10) {
        _quality++;
    }

    if (_days_remaining < 5) {
        _quality++;
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
