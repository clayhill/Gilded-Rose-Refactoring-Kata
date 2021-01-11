#ifndef GILDEDROSE_BACKSTAGE_PASSES_ITEM_H
#define GILDEDROSE_BACKSTAGE_PASSES_ITEM_H

class BackstagePassesItem
{
public:
    BackstagePassesItem(int days_remaining, int quality);
    void tick();
    int days_remaining() const;
    int quality() const;

private:
    int _days_remaining;
    int _quality;
};

#endif  //GILDEDROSE_BACKSTAGE_PASSES_ITEM_H