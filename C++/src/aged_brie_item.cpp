#include "aged_brie_item.h"

AgedBrieItem::AgedBrieItem(const int days_remaining, const int quality)
    : _days_remaining{days_remaining}
    , _quality{quality}
{
}
void AgedBrieItem::tick()
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
