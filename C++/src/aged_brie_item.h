#ifndef AGED_BRIE_ITEM_H
#define AGED_BRIE_ITEM_H

class AgedBrieItem
{
public:
    AgedBrieItem(int days_remaining, int quality);
    void tick();
    [[nodiscard]] int days_remaining() const { return _days_remaining; }
    [[nodiscard]] int quality() const { return _quality; }

private:
    int _days_remaining{};
    int _quality{};
};

#endif  //AGED_BRIE_ITEM_H
