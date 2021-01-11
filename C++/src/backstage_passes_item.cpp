#include "backstage_passes_item.h"

BackstagePassesItem::BackstagePassesItem(int days_remaining, int quality)
    : _days_remaining(days_remaining)
    , _quality(quality)
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

int BackstagePassesItem::days_remaining() const
{
    return _days_remaining;
}

int BackstagePassesItem::quality() const
{
    return _quality;
}
