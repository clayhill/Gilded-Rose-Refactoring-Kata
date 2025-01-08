package org.gildedrose

sealed class GildedRose {
    abstract val name: String
    abstract var quality: Int
    abstract var daysRemaining: Int
    abstract fun updateQuality()

    data class NormalItem(
        override var daysRemaining: Int,
        override var quality: Int,
    ) : GildedRose() {
        override val name: String = "Normal Item"

        override fun updateQuality() {
            if (quality > 0) {
                quality -= 1
            }
            daysRemaining -= 1
            if (daysRemaining < 0) {
                if (quality > 0) {
                    quality -= 1
                }
            }
        }
    }

    data class AgedBrie(
        override var daysRemaining: Int,
        override var quality: Int,
    ) : GildedRose() {
        override val name: String = "Aged Brie"

        override fun updateQuality() {
            if (quality < 50) {
                quality += 1
            }
            daysRemaining -= 1

            if (daysRemaining < 0) {
                if (quality < 50) {
                    quality += 1
                }
            }
        }
    }

    data class BackstagePasses(
        override var daysRemaining: Int,
        override var quality: Int,
    ) : GildedRose() {
        override val name: String = "Backstage passes to a TAFKAL80ETC concert"

        override fun updateQuality() {
            if (quality < 50) {
                quality += 1
                if (daysRemaining < 11) {
                    if (quality < 50) {
                        quality += 1
                    }
                }
                if (daysRemaining < 6) {
                    if (quality < 50) {
                        quality += 1
                    }
                }
            }
            daysRemaining -= 1
            if (daysRemaining < 0) {
                quality = 0
            }
        }
    }

    data class Sulfuras(
        override var daysRemaining: Int,
        override var quality: Int, // TODO: Could be set immmutable to 80 given tests?
    ) : GildedRose() {
        override val name: String = "Sulfuras, Hand of Ragnaros"
        override fun updateQuality() = Unit
    }

    data class ConjuredManaCake(
        override var daysRemaining: Int,
        override var quality: Int,
    ) : GildedRose() {
        override val name: String = "Conjured Mana Cake"

        override fun updateQuality() {
            if (quality > 0) {
                quality -= 1
            }
            daysRemaining -= 1

            if (daysRemaining < 0) {
                if (quality > 0) {
                    quality -= 1
                }
            }
        }
    }
}
