#ifndef BACKSTAGE_PASS_H
#define BACKSTAGE_PASS_H

class BackstagePass
{
public:
    BackstagePass(int days_remaining, int quality);
    void tick();
    [[nodiscard]] int days_remaining() const { return _days_remaining; }
    [[nodiscard]] int quality() const { return _quality; }

private:
    int _days_remaining{};
    int _quality{};
};

#endif  //BACKSTAGE_PASS_H
