package org.gildedrose


class GildedRose(var name: String, var daysRemaining: Int, var quality: Int) {
    fun updateQuality() {
        if (name != "Aged Brie" && name != "Backstage passes to a TAFKAL80ETC concert") {
            if (quality > 0) {
                if (name != "Sulfuras, Hand of Ragnaros") {
                    quality = quality - 1
                }
            }
        } else {
            if (quality < 50) {
                quality = quality + 1
                if (name == "Backstage passes to a TAFKAL80ETC concert") {
                    if (daysRemaining < 11) {
                        if (quality < 50) {
                            quality = quality + 1
                        }
                    }
                    if (daysRemaining < 6) {
                        if (quality < 50) {
                            quality = quality + 1
                        }
                    }
                }
            }
        }
        if (name != "Sulfuras, Hand of Ragnaros") {
            daysRemaining = daysRemaining - 1
        }
        if (daysRemaining < 0) {
            if (name != "Aged Brie") {
                if (name != "Backstage passes to a TAFKAL80ETC concert") {
                    if (quality > 0) {
                        if (name != "Sulfuras, Hand of Ragnaros") {
                            quality = quality - 1
                        }
                    }
                } else {
                    quality = quality - quality
                }
            } else {
                if (quality < 50) {
                    quality = quality + 1
                }
            }
        }
    }
}