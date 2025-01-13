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
    _normal_item = std::make_unique<NormalItem>(_days_remaining, _quality);
    _normal_item->tick();
}
void GildedRose::aged_brie_tick()
{
    _aged_brie_item = std::make_unique<AgedBrieItem>(_days_remaining, _quality);
    _aged_brie_item->tick();
}
void GildedRose::sulfuras_tick()
{
    _sulfuras_item = std::make_unique<SulfurasItem>(_days_remaining, _quality);
    _sulfuras_item->tick();
}
void GildedRose::backstage_pass_tick()
{
    _backstage_pass_item = std::make_unique<BackstagePass>(_days_remaining, _quality);
    _backstage_pass_item->tick();
}

int GildedRose::days_remaining() const
{
    if (_normal_item) {
        return _normal_item->days_remaining();
    }

    if (_aged_brie_item) {
        return _aged_brie_item->days_remaining();
    }

    if (_sulfuras_item) {
        return _sulfuras_item->days_remaining();
    }

    if (_backstage_pass_item) {
        return _backstage_pass_item->days_remaining();
    }

    return _days_remaining;
}

int GildedRose::quality() const
{
    if (_normal_item) {
        return _normal_item->quality();
    }

    if (_aged_brie_item) {
        return _aged_brie_item->quality();
    }

    if (_sulfuras_item) {
        return _sulfuras_item->quality();
    }

    if (_backstage_pass_item) {
        return _backstage_pass_item->quality();
    }

    return _quality;
}
