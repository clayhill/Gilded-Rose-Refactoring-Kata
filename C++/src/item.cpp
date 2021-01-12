#include "item.h"

Item::Item(int days_remaining, int quality)
    : _days_remaining(days_remaining)
    , _quality(quality)
{
}

void Item::tick()
{
}

int Item::days_remaining() const
{
    return _days_remaining;
}

int Item::quality() const
{
    return _quality;
}
