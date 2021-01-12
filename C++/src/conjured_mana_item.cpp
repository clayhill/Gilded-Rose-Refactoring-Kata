#include "conjured_mana_item.h"

ConjuredManaItem::ConjuredManaItem(int days_remaining, int quality)
    : Item(days_remaining, quality)
{
}

void ConjuredManaItem::tick()
{
    if (_quality > 0) {
        if (_days_remaining <= 0) {
            _quality -= 2;
        }

        _quality -= 2;
    }

    _days_remaining -= 1;
}
