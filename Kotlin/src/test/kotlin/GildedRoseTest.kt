import io.kotest.common.ExperimentalKotest
import io.kotest.core.spec.style.DescribeSpec
import io.kotest.matchers.shouldBe
import org.gildedrose.GildedRose

@OptIn(ExperimentalKotest::class)
class GildedRoseTest : DescribeSpec({
    describe("Normal Item") {
        it("before sell date") {
            val gildedRose = GildedRose("Normal Item", 5, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 9
            gildedRose.daysRemaining shouldBe 4
        }

        it("on sell date") {
            val gildedRose = GildedRose("Normal Item", 0, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 8
            gildedRose.daysRemaining shouldBe -1
        }

        it("after sell date") {
            val gildedRose = GildedRose("Normal Item", -10, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 8
            gildedRose.daysRemaining shouldBe -11
        }

        it("of zero quality") {
            val gildedRose = GildedRose("Normal Item", 5, 0)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 0
            gildedRose.daysRemaining shouldBe 4
        }
    }

    describe("Aged Brie") {
        it("before sell date") {
            val gildedRose = GildedRose("Aged Brie", 5, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 11
            gildedRose.daysRemaining shouldBe 4
        }

        it("with max quality") {
            val gildedRose = GildedRose("Aged Brie", 5, 50)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 50
            gildedRose.daysRemaining shouldBe 4
        }

        it("on sell date") {
            val gildedRose = GildedRose("Aged Brie", 0, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 12
            gildedRose.daysRemaining shouldBe -1
        }

        it("on sell date near max quality") {
            val gildedRose = GildedRose("Aged Brie", 0, 49)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 50
            gildedRose.daysRemaining shouldBe -1
        }

        it("on sell date with max quality") {
            val gildedRose = GildedRose("Aged Brie", 0, 50)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 50
            gildedRose.daysRemaining shouldBe -1
        }

        it("after sell date") {
            val gildedRose = GildedRose("Aged Brie", -10, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 12
            gildedRose.daysRemaining shouldBe -11
        }

        it("after sell date with max quality") {
            val gildedRose = GildedRose("Aged Brie", -10, 50)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 50
            gildedRose.daysRemaining shouldBe -11
        }
    }

    describe("Sulfuras") {
        it("before sell date") {
            val gildedRose = GildedRose("Sulfuras, Hand of Ragnaros", 5, 80)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 80
            gildedRose.daysRemaining shouldBe 5
        }

        it("on sell date") {
            val gildedRose = GildedRose("Sulfuras, Hand of Ragnaros", 0, 80)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 80
            gildedRose.daysRemaining shouldBe 0
        }

        it("after sell date") {
            val gildedRose = GildedRose("Sulfuras, Hand of Ragnaros", -10, 80)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 80
            gildedRose.daysRemaining shouldBe -10
        }
    }

    describe("Backstage Pass") {
        it("long before sell date") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", 11, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 11
            gildedRose.daysRemaining shouldBe 10
        }

        it("long before sell date at max quality") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", 11, 50)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 50
            gildedRose.daysRemaining shouldBe 10
        }

        it("medium close to sell date upper bound") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", 10, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 12
            gildedRose.daysRemaining shouldBe 9
        }

        it("medium close to sell date upper bound at max quality") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", 10, 50)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 50
            gildedRose.daysRemaining shouldBe 9
        }

        it("medium close to sell date lower bound") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", 6, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 12
            gildedRose.daysRemaining shouldBe 5
        }

        it("medium close to sell date lower bound at max quality") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", 6, 50)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 50
            gildedRose.daysRemaining shouldBe 5
        }

        it("very close to sell date upper bound") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", 5, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 13
            gildedRose.daysRemaining shouldBe 4
        }

        it("very close to sell date upper bound at max quality") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", 5, 50)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 50
            gildedRose.daysRemaining shouldBe 4
        }

        it("very close to sell date lower bound") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", 1, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 13
            gildedRose.daysRemaining shouldBe 0
        }

        it("very close to sell date lower bound at max quality") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", 1, 50)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 50
            gildedRose.daysRemaining shouldBe 0
        }

        it("on sell date") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", 0, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 0
            gildedRose.daysRemaining shouldBe -1
        }

        it("after sell date") {
            val gildedRose = GildedRose("Backstage passes to a TAFKAL80ETC concert", -10, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 0
            gildedRose.daysRemaining shouldBe -11
        }
    }

    describe("Conjured Mana Cake").config(enabled = false) {
        it("before sell date") {
            val gildedRose = GildedRose("Conjured Mana Cake", 5, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 8
            gildedRose.daysRemaining shouldBe 4
        }

        it("before sell date at zero quality") {
            val gildedRose = GildedRose("Conjured Mana Cake", 5, 0)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 0
            gildedRose.daysRemaining shouldBe 4
        }

        it("on sell date") {
            val gildedRose = GildedRose("Conjured Mana Cake", 0, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 6
            gildedRose.daysRemaining shouldBe -1
        }

        it("on sell date at zero quality") {
            val gildedRose = GildedRose("Conjured Mana Cake", 0, 0)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 0
            gildedRose.daysRemaining shouldBe -1
        }

        it("after sell date") {
            val gildedRose = GildedRose("Conjured Mana Cake", -10, 10)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 6
            gildedRose.daysRemaining shouldBe -11
        }

        it("after sell date at zero quality") {
            val gildedRose = GildedRose("Conjured Mana Cake", -10, 0)
            gildedRose.updateQuality()
            gildedRose.quality shouldBe 0
            gildedRose.daysRemaining shouldBe -11
        }
    }
})
