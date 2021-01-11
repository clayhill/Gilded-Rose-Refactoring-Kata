#ifndef GILDEDROSE_NORMAL_ITEM_H
#define GILDEDROSE_NORMAL_ITEM_H

class NormalItem
{
public:
    NormalItem(int days_remaining, int quality);
    void tick();
    int days_remaining() const;
    int quality() const;

private:
    int _days_remaining;
    int _quality;
};

#endif  //GILDEDROSE_NORMAL_ITEM_H
