#include "backstage_passes_item.h"

BackstagePassesItem::BackstagePassesItem(int days_remaining, int quality)
    : Item(days_remaining, quality)
{
}

void BackstagePassesItem::tick()
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
