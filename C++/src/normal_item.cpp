#include "normal_item.h"

NormalItem::NormalItem(int days_remaining, int quality)
    : _days_remaining(days_remaining)
    , _quality(quality)
{
}

void NormalItem::tick()
{
    if (_quality > 0) {
        if (_days_remaining <= 0) {
            _quality -= 1;
        }
        _quality -= 1;
    }

    _days_remaining -= 1;
}

int NormalItem::days_remaining() const
{
    return _days_remaining;
}

int NormalItem::quality() const
{
    return _quality;
}
