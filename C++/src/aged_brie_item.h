#ifndef GILDEDROSE_AGED_BRIE_ITEM_H
#define GILDEDROSE_AGED_BRIE_ITEM_H

class AgedBrieItem
{
public:
    AgedBrieItem(int days_remaining, int quality);
    void tick();
    int days_remaining() const;
    int quality() const;

private:
    int _days_remaining;
    int _quality;
};

#endif  //GILDEDROSE_AGED_BRIE_ITEM_H
