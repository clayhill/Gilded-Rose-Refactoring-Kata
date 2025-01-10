class GildedRose
  class NormalItem
    attr_reader :days_remaining, :quality

    def initialize(days_remaining, quality)
      @days_remaining = days_remaining
      @quality = quality
    end

    def tick
      @days_remaining -= 1
      return if @quality == 0

      @quality -= 1
      @quality -= 1 if @days_remaining <= 0
    end
  end

  class AgedBrieItem
    attr_reader :days_remaining, :quality

    def initialize(days_remaining, quality)
      @days_remaining = days_remaining
      @quality = quality
    end

    def tick
      @days_remaining -= 1
      return if @quality == 50

      @quality += 1
      @quality += 1 if @days_remaining <= 0 && @quality < 49
    end
  end

  class Sulfuras
    attr_reader :days_remaining, :quality

    def initialize(days_remaining, quality)
      @days_remaining = days_remaining
      @quality = quality
    end

    def tick

    end
  end

  class BackstagePass
    attr_reader :days_remaining, :quality

    def initialize(days_remaining, quality)
      @days_remaining = days_remaining
      @quality = quality
    end

    def tick
      @days_remaining -= 1
      return if @quality == 50
      return @quality = 0 if @days_remaining < 0

      @quality += 1
      @quality += 1 if @days_remaining < 10
      @quality += 1 if @days_remaining < 5
    end
  end

  attr_reader :days_remaining, :quality

  def initialize(name:, days_remaining:, quality:)
    @item = klass_for(name).new(days_remaining, quality)
  end

  def tick
    @item.tick
  end

  def days_remaining
    @item.days_remaining
  end

  def quality
    @item.quality
  end

  private

  def klass_for(name)
    case name
    when "Normal Item"
      NormalItem
    when "Aged Brie"
      AgedBrieItem
    when "Sulfuras, Hand of Ragnaros"
      Sulfuras
    when "Backstage passes to a TAFKAL80ETC concert"
      BackstagePass
    end
  end
end
