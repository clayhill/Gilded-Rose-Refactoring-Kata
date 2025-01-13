#ifndef SULFURAS_H
#define SULFURAS_H

class SulfurasItem
{
public:
    SulfurasItem(int days_remaining, int quality);
    void tick();
    [[nodiscard]] int days_remaining() const { return _days_remaining; }
    [[nodiscard]] int quality() const { return _quality; }

private:
    int _days_remaining{};
    int _quality{};
};

#endif  //SULFURAS_H
