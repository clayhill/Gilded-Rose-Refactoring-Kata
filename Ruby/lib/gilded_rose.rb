module GildedRose
  class Item
    attr_reader :days_remaining, :quality

    def initialize(days_remaining, quality)
      @days_remaining = days_remaining
      @quality = quality
    end

    def tick
      # Do nothing
    end
  end

  class NormalItem < Item
    def tick
      @days_remaining -= 1
      return if @quality == 0

      @quality -= 1
      @quality -= 1 if @days_remaining <= 0
    end
  end

  class AgedBrieItem < Item
    def tick
      @days_remaining -= 1
      return if @quality == 50

      @quality += 1
      @quality += 1 if @days_remaining <= 0 && @quality < 49
    end
  end

  class BackstagePass < Item
    def tick
      @days_remaining -= 1
      return if @quality == 50
      return @quality = 0 if @days_remaining < 0

      @quality += 1
      @quality += 1 if @days_remaining < 10
      @quality += 1 if @days_remaining < 5
    end
  end

  def self.for(name:, days_remaining:, quality:)
    klass_for(name).new(days_remaining, quality)
  end

  private

  def self.klass_for(name)
    case name
    when "Normal Item"
      NormalItem
    when "Aged Brie"
      AgedBrieItem
    when "Sulfuras, Hand of Ragnaros"
      Item
    when "Backstage passes to a TAFKAL80ETC concert"
      BackstagePass
    end
  end
end
