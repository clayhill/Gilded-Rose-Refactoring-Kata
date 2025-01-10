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

  attr_reader :name, :days_remaining, :quality

  def initialize(name:, days_remaining:, quality:)
    @name = name
    @days_remaining = days_remaining
    @quality = quality
  end

  def tick
    case @name
    when "Normal Item"
      @item = NormalItem.new(@days_remaining, @quality)
      @item.tick
    when "Aged Brie"
      @item = AgedBrieItem.new(@days_remaining, @quality)
      @item.tick
    when "Sulfuras, Hand of Ragnaros"
      @item = Sulfuras.new(@days_remaining, @quality)
      @item.tick
    when "Backstage passes to a TAFKAL80ETC concert"
      @item = BackstagePass.new(@days_remaining, @quality)
      @item.tick
    end
  end

  def days_remaining
    return @item.days_remaining if @item
    @days_remaining
  end

  def quality
    return @item.quality if @item
    @quality
  end
end
