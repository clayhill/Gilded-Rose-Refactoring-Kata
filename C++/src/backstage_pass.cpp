#include "backstage_pass.h"

BackstagePass::BackstagePass(const int days_remaining, const int quality)
    : Item{days_remaining, quality}
{
}

void BackstagePass::tick()
{
    _days_remaining--;

    if (_quality == 50) {
        return;
    }

    if (_days_remaining < 0) {
        _quality = 0;
        return;
    }

    _quality++;

    if (_days_remaining < 10) {
        _quality++;
    }

    if (_days_remaining < 5) {
        _quality++;
    }
}
