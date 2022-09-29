package com.gildedrose;

import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class GildedRoseTest {

    Item updateQualityForItemWith(int sellIn, int quality, String name) {
        Item[] items = new Item[] { new Item(name, sellIn, quality) };
        GildedRose app = new GildedRose(items);
        app.updateQuality();
        return items[0];
    }

    @Test
    void testNormalItemBeforeSellDate() {
        Item item = updateQualityForItemWith(5, 10, "normal");
        assertEquals(4, item.sellIn);
        assertEquals(9, item.quality);
    }


    @Test
    void testNormalItemOnSellDate() {
        Item item = updateQualityForItemWith(0, 10, "normal");
        assertEquals(-1, item.sellIn);
        assertEquals(8, item.quality);
    }

    @Test
    void testNormalItemAfterSellDate() {
        Item item = updateQualityForItemWith(-10, 10, "normal");
        assertEquals(-11, item.sellIn);
        assertEquals(8, item.quality);
    }

    @Test
    void testNormalItemOfZeroQuality() {
        Item item = updateQualityForItemWith(5, 0, "normal");
        assertEquals(4, item.sellIn);
        assertEquals(0, item.quality);
    }

    @Test
    void testBrieBeforeSellDate() {
        Item item = updateQualityForItemWith(5, 10, "Aged Brie");
        assertEquals(4, item.sellIn);
        assertEquals(11, item.quality);
    }

    @Test
    void testBrieBeforeSellDateWithMaxQuality() {
        Item item = updateQualityForItemWith(5, 50, "Aged Brie");
        assertEquals(4, item.sellIn);
        assertEquals(50, item.quality);
    }

    @Test
    void testBrieOnSellDate() {
        Item item = updateQualityForItemWith(0, 10, "Aged Brie");
        assertEquals(-1, item.sellIn);
        assertEquals(12, item.quality);
    }

    @Test
    void testBrieOnSellDateNearMaxQuality() {
        Item item = updateQualityForItemWith(0, 49, "Aged Brie");
        assertEquals(-1, item.sellIn);
        assertEquals(50, item.quality);
    }

    @Test
    void testBrieOnSellDateWithMaxQuality() {
        Item item = updateQualityForItemWith(0, 50, "Aged Brie");
        assertEquals(-1, item.sellIn);
        assertEquals(50, item.quality);
    }

    @Test
    void testBrieAfterSellDate() {
        Item item = updateQualityForItemWith(-10, 10, "Aged Brie");
        assertEquals(-11, item.sellIn);
        assertEquals(12, item.quality);
    }

    @Test
    void testBrieAfterSellDateWithMaxQuality() {
        Item item = updateQualityForItemWith(-10, 50, "Aged Brie");
        assertEquals(-11, item.sellIn);
        assertEquals(50, item.quality);
    }

    @Test
    void testSulfurasBeforeSellDate() {
        Item item = updateQualityForItemWith(5, 80, "Sulfuras, Hand of Ragnaros");
        assertEquals(5, item.sellIn);
        assertEquals(80, item.quality);
    }

    @Test
    void testSulfurasOnSellDate() {
        Item item = updateQualityForItemWith(0, 80, "Sulfuras, Hand of Ragnaros");
        assertEquals(0, item.sellIn);
        assertEquals(80, item.quality);
    }

    @Test
    void testSulfurasAfterSellDate() {
        Item item = updateQualityForItemWith(-10, 80, "Sulfuras, Hand of Ragnaros");
        assertEquals(-10, item.sellIn);
        assertEquals(80, item.quality);
    }

    @Test
    void testBackstagePassLongBeforeSellDate() {
        Item item = updateQualityForItemWith(11, 10, "Backstage passes to a TAFKAL80ETC concert");
        assertEquals(10, item.sellIn);
        assertEquals(11, item.quality);
    }

    @Test
    void testBackstagePassMediumCloseToSellDateUpperBound() {
        Item item = updateQualityForItemWith(10, 10, "Backstage passes to a TAFKAL80ETC concert");
        assertEquals(9, item.sellIn);
        assertEquals(12, item.quality);
    }

    @Test
    void testBackstagePassMediumCloseToSellDateUpperBoundAtMaxQuality() {
        Item item = updateQualityForItemWith(10, 50, "Backstage passes to a TAFKAL80ETC concert");
        assertEquals(9, item.sellIn);
        assertEquals(50, item.quality);
    }

    @Test
    void testBackstagePassMediumCloseToSellDateLowerBound() {
        Item item = updateQualityForItemWith(6, 10, "Backstage passes to a TAFKAL80ETC concert");
        assertEquals(5, item.sellIn);
        assertEquals(12, item.quality);
    }

    @Test
    void testBackstagePassMediumCloseToSellDateLowerBoundAtMaxQuality() {
        Item item = updateQualityForItemWith(6, 50, "Backstage passes to a TAFKAL80ETC concert");
        assertEquals(5, item.sellIn);
        assertEquals(50, item.quality);
    }

    @Test
    void testBackstagePassVeryCloseToSellDateUpperBound() {
        Item item = updateQualityForItemWith(5, 10, "Backstage passes to a TAFKAL80ETC concert");
        assertEquals(4, item.sellIn);
        assertEquals(13, item.quality);
    }

    @Test
    void testBackstagePassVeryCloseToSellDateUpperBoundAtMaxQuality() {
        Item item = updateQualityForItemWith(5, 50, "Backstage passes to a TAFKAL80ETC concert");
        assertEquals(4, item.sellIn);
        assertEquals(50, item.quality);
    }

    @Test
    void testBackstagePassVeryCloseToSellDateLowerBound() {
        Item item = updateQualityForItemWith(1, 10, "Backstage passes to a TAFKAL80ETC concert");
        assertEquals(0, item.sellIn);
        assertEquals(13, item.quality);
    }

    @Test
    void testBackstagePassVeryCloseToSellDateLowerBoundAtMaxQuality() {
        Item item = updateQualityForItemWith(1, 50, "Backstage passes to a TAFKAL80ETC concert");
        assertEquals(0, item.sellIn);
        assertEquals(50, item.quality);
    }

    @Test
    void testBackstagePassOnSellDate() {
        Item item = updateQualityForItemWith(0, 10, "Backstage passes to a TAFKAL80ETC concert");
        assertEquals(-1, item.sellIn);
        assertEquals(0, item.quality);
    }

    @Test
    void testBackstagePassAfterSellDate() {
        Item item = updateQualityForItemWith(-10, 10, "Backstage passes to a TAFKAL80ETC concert");
        assertEquals(-11, item.sellIn);
        assertEquals(0, item.quality);
    }

    @Disabled
    @Test
    void testConjuredItemBeforeSellDate() {
        Item item = updateQualityForItemWith(5, 10, "Conjured Mana Cake");
        assertEquals(4, item.sellIn);
        assertEquals(8, item.quality);
    }

    @Disabled
    @Test
    void testConjuredItemAtZeroQuality() {
        Item item = updateQualityForItemWith(5, 0, "Conjured Mana Cake");
        assertEquals(4, item.sellIn);
        assertEquals(0, item.quality);
    }

    @Disabled
    @Test
    void testConjuredItemOnSellDate() {
        Item item = updateQualityForItemWith(0, 10, "Conjured Mana Cake");
        assertEquals(-1, item.sellIn);
        assertEquals(6, item.quality);
    }

    @Disabled
    @Test
    void testConjuredItemOnSellDateAtZeroQuality() {
        Item item = updateQualityForItemWith(0, 0, "Conjured Mana Cake");
        assertEquals(-1, item.sellIn);
        assertEquals(0, item.quality);
    }

    @Disabled
    @Test
    void testConjuredItemAfterSellDate() {
        Item item = updateQualityForItemWith(-10, 10, "Conjured Mana Cake");
        assertEquals(-11, item.sellIn);
        assertEquals(6, item.quality);
    }

    @Disabled
    @Test
    void testConjuredItemAfterSellDateAtZeroQuality() {
        Item item = updateQualityForItemWith(-10, 0, "Conjured Mana Cake");
        assertEquals(-11, item.sellIn);
        assertEquals(0, item.quality);
    }

    @Test
    void testSeveralItems() {
        Item[] items = new Item[]{
            new Item("normal", 5, 10),
            new Item("Aged Brie", 3, 10)
        };
        GildedRose app = new GildedRose(items);
        app.updateQuality();
        assertEquals(9, app.items[0].quality);
        assertEquals(4, app.items[0].sellIn);
        assertEquals(11, app.items[1].quality);
        assertEquals(2, app.items[1].sellIn);
    }
}
