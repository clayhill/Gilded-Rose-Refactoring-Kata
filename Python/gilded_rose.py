class GildedRose:

    def __init__(self, name, days_remaining, quality):
        self.name = name
        self.days_remaining = days_remaining
        self.quality = quality

    def tick(self):
        if self.name != "Aged Brie" and self.name != "Backstage passes to a TAFKAL80ETC concert":
            if self.quality > 0:
                if self.name != "Sulfuras, Hand of Ragnaros":
                    self.quality = self.quality - 1
        else:
            if self.quality < 50:
                self.quality = self.quality + 1
                if self.name == "Backstage passes to a TAFKAL80ETC concert":
                    if self.days_remaining < 11:
                        if self.quality < 50:
                            self.quality = self.quality + 1
                    if self.days_remaining < 6:
                        if self.quality < 50:
                            self.quality = self.quality + 1
        if self.name != "Sulfuras, Hand of Ragnaros":
            self.days_remaining = self.days_remaining - 1
        if self.days_remaining < 0:
            if self.name != "Aged Brie":
                if self.name != "Backstage passes to a TAFKAL80ETC concert":
                    if self.quality > 0:
                        if self.name != "Sulfuras, Hand of Ragnaros":
                            self.quality = self.quality - 1
                else:
                    self.quality = self.quality - self.quality
            else:
                if self.quality < 50:
                    self.quality = self.quality + 1
