class VowelFinder
  include Enumerable
  def initialize(s)
    @string = s
  end

  def each
    @string.scan(/[aeiou]/) do |c|
      yield c
    end
  end
end

# VowelFinder.new("the quick brown fox jumped of the red fox").inject(:+)
