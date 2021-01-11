#include "aged_brie_item.h"

AgedBrieItem::AgedBrieItem(int days_remaining, int quality)
    : _days_remaining(days_remaining)
    , _quality(quality)
{
}

void AgedBrieItem::tick()
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

int AgedBrieItem::days_remaining() const
{
    return _days_remaining;
}

int AgedBrieItem::quality() const
{
    return _quality;
}
