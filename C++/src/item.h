#ifndef ITEM_H
#define ITEM_H

class Item
{
public:
    Item(int days_remaining, int quality);
    virtual ~Item() = default;
    virtual void tick() = 0;
    [[nodiscard]] int days_remaining() const { return _days_remaining; }
    [[nodiscard]] int quality() const { return _quality; }

protected:
    int _days_remaining{};
    int _quality{};
};

#endif  //ITEM_H
