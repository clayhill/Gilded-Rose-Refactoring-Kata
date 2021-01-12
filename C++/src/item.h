#ifndef GILDEDROSE_ITEM_H
#define GILDEDROSE_ITEM_H

class Item
{
public:
    Item(int days_remaining, int quality);
    virtual ~Item() = default;
    virtual void tick();
    int days_remaining() const;
    int quality() const;

protected:
    int _days_remaining;
    int _quality;
};

#endif  //GILDEDROSE_ITEM_H
