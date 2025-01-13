#ifndef NORMAL_ITEM_H
#define NORMAL_ITEM_H

class NormalItem
{
public:
    NormalItem(int days_remaining, int quality);
    void tick();
    [[nodiscard]] int days_remaining() const { return _days_remaining; }
    [[nodiscard]] int quality() const { return _quality; }

private:
    int _days_remaining{};
    int _quality{};
};

#endif  //NORMAL_ITEM_H
