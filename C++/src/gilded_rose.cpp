#include "gilded_rose.h"

#include <string>

namespace
{
std::unique_ptr<Item> createItem(const std::string &name, int days_remaining, int quality)
{
    if (name == "Normal Item") {
        return std::make_unique<NormalItem>(days_remaining, quality);
    }

    if (name == "Aged Brie") {
        return std::make_unique<AgedBrieItem>(days_remaining, quality);
    }

    if (name == "Sulfuras, Hand of Ragnaros") {
        return std::make_unique<SulfurasItem>(days_remaining, quality);
    }

    if (name == "Backstage passes to a TAFKAL80ETC concert") {
        return std::make_unique<BackstagePass>(days_remaining, quality);
    }
}
}  // namespace

GildedRose::GildedRose(const std::string &name, int days_remaining, int quality)
    : _item(createItem(name, days_remaining, quality))
{
}

void GildedRose::tick()
{
    _item->tick();
}

int GildedRose::days_remaining() const
{
    return _item->days_remaining();
}

int GildedRose::quality() const
{
    return _item->quality();
}
