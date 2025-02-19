#include "normal_item.h"

NormalItem::NormalItem(const int days_remaining, const int quality)
    : Item{days_remaining, quality}
{
}

void NormalItem::tick()
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
