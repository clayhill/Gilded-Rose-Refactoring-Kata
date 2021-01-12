#include "conjured_mana_item.h"

ConjuredManaItem::ConjuredManaItem(int days_remaining, int quality)
    : Item(days_remaining, quality)
{
}

void ConjuredManaItem::tick()
{
    _days_remaining -= 1;
    _quality -= 2;
}
