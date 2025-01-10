class GildedRose
  attr_reader :name, :days_remaining, :quality

  def initialize(name:, days_remaining:, quality:)
    @name = name
    @days_remaining = days_remaining
    @quality = quality
  end

  def normal_tick
    @days_remaining -= 1
    return if @quality == 0

    @quality -= 1
    @quality -= 1 if @days_remaining <= 0
  end

  def aged_brie_tick
    @days_remaining -= 1
    return if @quality == 50

    @quality += 1
    @quality += 1 if @days_remaining <= 0 && @quality < 49
  end

  def sulfuras_tick
  end

  def backstage_pass_tick
    @days_remaining -= 1
    return if @quality == 50
    return @quality = 0 if @days_remaining < 0

    @quality += 1
    @quality += 1 if @days_remaining < 10
    @quality += 1 if @days_remaining < 5
  end

  def tick
    case @name
    when "Normal Item"
      normal_tick
    when "Aged Brie"
      aged_brie_tick
    when "Sulfuras, Hand of Ragnaros"
      sulfuras_tick
    when "Backstage passes to a TAFKAL80ETC concert"
      backstage_pass_tick
    end
  end
end
