#include "normal_item.h"

NormalItem::NormalItem(int days_remaining, int quality)
    : Item(days_remaining, quality)
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
