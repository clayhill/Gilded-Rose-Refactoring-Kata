#include <gtest/gtest.h>
#include "GildedRose/gilded_rose.h"

using namespace ::testing;

class GildedRoseNormalItem : public Test
{
protected:
    std::string name{"Normal Item"};
};

TEST_F(GildedRoseNormalItem, BeforeSellDate)
{
    GildedRose gilded_rose{name, 5, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 4);
    EXPECT_EQ(gilded_rose.quality(), 9);
}

TEST_F(GildedRoseNormalItem, OnSellDate)
{
    GildedRose gilded_rose{name, 0, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -1);
    EXPECT_EQ(gilded_rose.quality(), 8);
}

TEST_F(GildedRoseNormalItem, AfterSellDate)
{
    GildedRose gilded_rose{name, -10, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -11);
    EXPECT_EQ(gilded_rose.quality(), 8);
}

TEST_F(GildedRoseNormalItem, OfZeroQuality)
{
    GildedRose gilded_rose{name, 5, 0};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 4);
    EXPECT_EQ(gilded_rose.quality(), 0);
}

class GildedRoseAgedBrie : public Test
{
protected:
    std::string name{"Aged Brie"};
};

TEST_F(GildedRoseAgedBrie, BeforeSellDate)
{
    GildedRose gilded_rose{name, 5, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 4);
    EXPECT_EQ(gilded_rose.quality(), 11);
}

TEST_F(GildedRoseAgedBrie, WithMaxQuality)
{
    GildedRose gilded_rose{name, 5, 50};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 4);
    EXPECT_EQ(gilded_rose.quality(), 50);
}

TEST_F(GildedRoseAgedBrie, OnSellDate)
{
    GildedRose gilded_rose{name, 0, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -1);
    EXPECT_EQ(gilded_rose.quality(), 12);
}

TEST_F(GildedRoseAgedBrie, OnSellDateNearMaxQuality)
{
    GildedRose gilded_rose{name, 0, 49};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -1);
    EXPECT_EQ(gilded_rose.quality(), 50);
}

TEST_F(GildedRoseAgedBrie, AfterSellDate)
{
    GildedRose gilded_rose{name, -10, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -11);
    EXPECT_EQ(gilded_rose.quality(), 12);
}

TEST_F(GildedRoseAgedBrie, AfterSellDateWithMaxQuality)
{
    GildedRose gilded_rose{name, -10, 50};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -11);
    EXPECT_EQ(gilded_rose.quality(), 50);
}

class GildedRoseSulfuras : public Test
{
protected:
    std::string name{"Sulfuras, Hand of Ragnaros"};
};

TEST_F(GildedRoseSulfuras, BeforeSellDate)
{
    GildedRose gilded_rose{name, 5, 80};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 5);
    EXPECT_EQ(gilded_rose.quality(), 80);
}

TEST_F(GildedRoseSulfuras, OnSellDate)
{
    GildedRose gilded_rose{name, 0, 80};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 0);
    EXPECT_EQ(gilded_rose.quality(), 80);
}

TEST_F(GildedRoseSulfuras, AfterSellDate)
{
    GildedRose gilded_rose{name, -10, 80};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -10);
    EXPECT_EQ(gilded_rose.quality(), 80);
}

class GildedRoseBackstagePass : public Test
{
protected:
    std::string name{"Backstage passes to a TAFKAL80ETC concert"};
};

TEST_F(GildedRoseBackstagePass, LongBeforeSellDate)
{
    GildedRose gilded_rose{name, 11, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 10);
    EXPECT_EQ(gilded_rose.quality(), 11);
}

TEST_F(GildedRoseBackstagePass, LongBeforeSellDateAtMaxQuality)
{
    GildedRose gilded_rose{name, 11, 50};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 10);
    EXPECT_EQ(gilded_rose.quality(), 50);
}

TEST_F(GildedRoseBackstagePass, MediumCloseToSellDateUpperBound)
{
    GildedRose gilded_rose{name, 10, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 9);
    EXPECT_EQ(gilded_rose.quality(), 12);
}

TEST_F(GildedRoseBackstagePass, MediumCloseToSellDateUpperBoundAtMaxQuality)
{
    GildedRose gilded_rose{name, 10, 50};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 9);
    EXPECT_EQ(gilded_rose.quality(), 50);
}

TEST_F(GildedRoseBackstagePass, MediumCloseToSellDateLowerBound)
{
    GildedRose gilded_rose{name, 6, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 5);
    EXPECT_EQ(gilded_rose.quality(), 12);
}

TEST_F(GildedRoseBackstagePass, MediumCloseToSellDateLowerBoundAtMaxQuality)
{
    GildedRose gilded_rose{name, 6, 50};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 5);
    EXPECT_EQ(gilded_rose.quality(), 50);
}

TEST_F(GildedRoseBackstagePass, VeryCloseToSellDateUpperBound)
{
    GildedRose gilded_rose{name, 5, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 4);
    EXPECT_EQ(gilded_rose.quality(), 13);
}

TEST_F(GildedRoseBackstagePass, VeryCloseToSellDateUpperBoundAtMaxQuality)
{
    GildedRose gilded_rose{name, 5, 50};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 4);
    EXPECT_EQ(gilded_rose.quality(), 50);
}

TEST_F(GildedRoseBackstagePass, VeryCloseToSellDateLowerBound)
{
    GildedRose gilded_rose{name, 1, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 0);
    EXPECT_EQ(gilded_rose.quality(), 13);
}

TEST_F(GildedRoseBackstagePass, VeryCloseToSellDateLowerBoundAtMaxQuality)
{
    GildedRose gilded_rose{name, 1, 50};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 0);
    EXPECT_EQ(gilded_rose.quality(), 50);
}

TEST_F(GildedRoseBackstagePass, OnSellDate)
{
    GildedRose gilded_rose{name, 0, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -1);
    EXPECT_EQ(gilded_rose.quality(), 0);
}

TEST_F(GildedRoseBackstagePass, AfterSellDate)
{
    GildedRose gilded_rose{name, -10, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -11);
    EXPECT_EQ(gilded_rose.quality(), 0);
}

class GildedRoseConjuredMana : public Test
{
protected:
    std::string name{"Conjured Mana Cake"};
};

TEST_F(GildedRoseConjuredMana, DISABLED_BeforeSellDate)
{
    GildedRose gilded_rose{name, 5, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 4);
    EXPECT_EQ(gilded_rose.quality(), 8);
}

TEST_F(GildedRoseConjuredMana, DISABLED_BeforeSellDateAtZeroQuality)
{
    GildedRose gilded_rose{name, 5, 0};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), 4);
    EXPECT_EQ(gilded_rose.quality(), 0);
}

TEST_F(GildedRoseConjuredMana, DISABLED_OnSellDate)
{
    GildedRose gilded_rose{name, 0, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -1);
    EXPECT_EQ(gilded_rose.quality(), 6);
}

TEST_F(GildedRoseConjuredMana, DISABLED_OnSellDateAtZeroQuality)
{
    GildedRose gilded_rose{name, 0, 0};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -1);
    EXPECT_EQ(gilded_rose.quality(), 0);
}

TEST_F(GildedRoseConjuredMana, DISABLED_AfterSellDate)
{
    GildedRose gilded_rose{name, -10, 10};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -11);
    EXPECT_EQ(gilded_rose.quality(), 6);
}

TEST_F(GildedRoseConjuredMana, DISABLED_AfterSellDateAtZeroQuality)
{
    GildedRose gilded_rose{name, -10, 0};
    gilded_rose.tick();

    EXPECT_EQ(gilded_rose.days_remaining(), -11);
    EXPECT_EQ(gilded_rose.quality(), 0);
}
