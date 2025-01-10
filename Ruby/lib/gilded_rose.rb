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
    if @name == "Normal Item"
      return normal_tick
    end

    if @name == "Aged Brie"
      return aged_brie_tick
    end

    if @name == "Sulfuras, Hand of Ragnaros"
      return sulfuras_tick
    end

    if @name == "Backstage passes to a TAFKAL80ETC concert"
      return backstage_pass_tick
    end

    if @name != "Aged Brie" and @name != "Backstage passes to a TAFKAL80ETC concert"
      if @quality > 0
        if @name != "Sulfuras, Hand of Ragnaros"
          @quality = @quality - 1
        end
      end
    else
      if @quality < 50
        @quality = @quality + 1
        if @name == "Backstage passes to a TAFKAL80ETC concert"
          if @days_remaining < 11
            if @quality < 50
              @quality = @quality + 1
            end
          end
          if @days_remaining < 6
            if @quality < 50
              @quality = @quality + 1
            end
          end
        end
      end
    end
    if @name != "Sulfuras, Hand of Ragnaros"
      @days_remaining = @days_remaining - 1
    end
    if @days_remaining < 0
      if @name != "Aged Brie"
        if @name != "Backstage passes to a TAFKAL80ETC concert"
          if @quality > 0
            if @name != "Sulfuras, Hand of Ragnaros"
              @quality = @quality - 1
            end
          end
        else
          @quality = @quality - @quality
        end
      else
        if @quality < 50
          @quality = @quality + 1
        end
      end
    end
  end
end
