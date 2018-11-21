import unittest
from gilded_rose import GildedRose


class GildedRoseNormalItemTest(unittest.TestCase):
    def setUp(self):
        self.name = "Normal Item"

    def test_before_sell_date(self):
        gilded_rose = GildedRose(self.name, 5, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 4)
        self.assertEqual(gilded_rose.quality, 9)

    def test_on_sell_date(self):
        gilded_rose = GildedRose(self.name, 0, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -1)
        self.assertEqual(gilded_rose.quality, 8)

    def test_after_sell_date(self):
        gilded_rose = GildedRose(self.name, -10, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -11)
        self.assertEqual(gilded_rose.quality, 8)

    def test_of_zero_quality(self):
        gilded_rose = GildedRose(self.name, 5, 0)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 4)
        self.assertEqual(gilded_rose.quality, 0)


class GildedRoseAgedBrieTest(unittest.TestCase):
    def setUp(self):
        self.name = "Aged Brie"

    def test_before_sell_date(self):
        gilded_rose = GildedRose(self.name, 5, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 4)
        self.assertEqual(gilded_rose.quality, 11)

    def test_with_max_quality(self):
        gilded_rose = GildedRose(self.name, 5, 50)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 4)
        self.assertEqual(gilded_rose.quality, 50)

    def test_on_sell_date(self):
        gilded_rose = GildedRose(self.name, 0, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -1)
        self.assertEqual(gilded_rose.quality, 12)

    def test_on_sell_date_near_max_quality(self):
        gilded_rose = GildedRose(self.name, 0, 49)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -1)
        self.assertEqual(gilded_rose.quality, 50)

    def test_on_sell_date_with_max_quality(self):
        gilded_rose = GildedRose(self.name, 0, 50)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -1)
        self.assertEqual(gilded_rose.quality, 50)

    def test_after_sell_date(self):
        gilded_rose = GildedRose(self.name, -10, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -11)
        self.assertEqual(gilded_rose.quality, 12)

    def test_after_sell_date_with_max_quality(self):
        gilded_rose = GildedRose(self.name, -10, 50)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -11)
        self.assertEqual(gilded_rose.quality, 50)


class GildedRoseSulfurasTest(unittest.TestCase):
    def setUp(self):
        self.name = "Sulfuras, Hand of Ragnaros"

    def test_before_sell_date(self):
        gilded_rose = GildedRose(self.name, 5, 80)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 5)
        self.assertEqual(gilded_rose.quality, 80)

    def test_on_sell_date(self):
        gilded_rose = GildedRose(self.name, 0, 80)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 0)
        self.assertEqual(gilded_rose.quality, 80)

    def test_after_sell_date(self):
        gilded_rose = GildedRose(self.name, -10, 80)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -10)
        self.assertEqual(gilded_rose.quality, 80)


class GildedRoseBackstagePassTest(unittest.TestCase):
    def setUp(self):
        self.name = "Backstage passes to a TAFKAL80ETC concert"

    def test_long_before_sell_date(self):
        gilded_rose = GildedRose(self.name, 11, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 10)
        self.assertEqual(gilded_rose.quality, 11)

    def test_long_before_sell_date_at_max_quality(self):
        gilded_rose = GildedRose(self.name, 11, 50)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 10)
        self.assertEqual(gilded_rose.quality, 50)

    def test_medium_close_to_sell_date_upper_bound(self):
        gilded_rose = GildedRose(self.name, 10, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 9)
        self.assertEqual(gilded_rose.quality, 12)

    def test_medium_close_to_sell_date_upper_bound_at_max_quality(self):
        gilded_rose = GildedRose(self.name, 10, 50)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 9)
        self.assertEqual(gilded_rose.quality, 50)

    def test_medium_close_to_sell_date_lower_bound(self):
        gilded_rose = GildedRose(self.name, 6, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 5)
        self.assertEqual(gilded_rose.quality, 12)

    def test_medium_close_to_sell_date_lower_bound_at_max_quality(self):
        gilded_rose = GildedRose(self.name, 6, 50)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 5)
        self.assertEqual(gilded_rose.quality, 50)

    def test_very_close_to_sell_date_upper_bound(self):
        gilded_rose = GildedRose(self.name, 5, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 4)
        self.assertEqual(gilded_rose.quality, 13)

    def test_very_close_to_sell_date_upper_bound_at_max_quality(self):
        gilded_rose = GildedRose(self.name, 5, 50)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 4)
        self.assertEqual(gilded_rose.quality, 50)

    def test_very_close_to_sell_date_lower_bound(self):
        gilded_rose = GildedRose(self.name, 1, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 0)
        self.assertEqual(gilded_rose.quality, 13)

    def test_very_close_to_sell_date_lower_bound_at_max_quality(self):
        gilded_rose = GildedRose(self.name, 1, 50)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 0)
        self.assertEqual(gilded_rose.quality, 50)

    def test_on_sell_date(self):
        gilded_rose = GildedRose(self.name, 0, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -1)
        self.assertEqual(gilded_rose.quality, 0)

    def test_after_sell_date(self):
        gilded_rose = GildedRose(self.name, -10, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -11)
        self.assertEqual(gilded_rose.quality, 0)


class GildedRoseConjuredManaTest(unittest.TestCase):
    def setUp(self):
        self.name = "Conjured Mana Cake"

    @unittest.skip("Not yet implemented")
    def test_before_sell_date(self):
        gilded_rose = GildedRose(self.name, 5, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 4)
        self.assertEqual(gilded_rose.quality, 8)

    @unittest.skip("Not yet implemented")
    def test_before_sell_date_at_zero_quality(self):
        gilded_rose = GildedRose(self.name, 5, 0)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, 4)
        self.assertEqual(gilded_rose.quality, 0)

    @unittest.skip("Not yet implemented")
    def test_on_sell_date(self):
        gilded_rose = GildedRose(self.name, 0, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -1)
        self.assertEqual(gilded_rose.quality, 6)

    @unittest.skip("Not yet implemented")
    def test_on_sell_date_at_zero_quality(self):
        gilded_rose = GildedRose(self.name, 0, 0)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -1)
        self.assertEqual(gilded_rose.quality, 0)

    @unittest.skip("Not yet implemented")
    def test_after_sell_date(self):
        gilded_rose = GildedRose(self.name, -10, 10)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -11)
        self.assertEqual(gilded_rose.quality, 6)

    @unittest.skip("Not yet implemented")
    def test_after_sell_date_at_zero_quality(self):
        gilded_rose = GildedRose(self.name, -10, 0)
        gilded_rose.tick()
        self.assertEqual(gilded_rose.days_remaining, -11)
        self.assertEqual(gilded_rose.quality, 0)
