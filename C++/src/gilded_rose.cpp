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
        _item = std::make_unique<NormalItem>(_days_remaining, _quality);
        _item->tick();
    }
    else if (_name == "Aged Brie") {
        _item = std::make_unique<AgedBrieItem>(_days_remaining, _quality);
        _item->tick();
    }
    else if (_name == "Sulfuras, Hand of Ragnaros") {
        _sulfuras_item = std::make_unique<SulfurasItem>(_days_remaining, _quality);
        _sulfuras_item->tick();
    }
    else if (_name == "Backstage passes to a TAFKAL80ETC concert") {
        _backstage_pass_item = std::make_unique<BackstagePass>(_days_remaining, _quality);
        _backstage_pass_item->tick();
    }
}

int GildedRose::days_remaining() const
{
    if (_item) {
        return _item->days_remaining();
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
    if (_item) {
        return _item->quality();
    }

    if (_sulfuras_item) {
        return _sulfuras_item->quality();
    }

    if (_backstage_pass_item) {
        return _backstage_pass_item->quality();
    }

    return _quality;
}
