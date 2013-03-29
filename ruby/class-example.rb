class BookInStock
  @@total = 0
  attr_reader :author, :isbn, :price
  def initialize(isbn, price)
    @isbn = isbn
    @price = Float(price)
    @@total += 1
    hello()
  end
  def to_s
    "ISBN: #{@isbn}, Price: #{@price}"
  end
  def total
    @@total
  end
  def hello
    puts "hello from "+self.to_s
  end
end

b1 = BookInStock.new("isbn1", 2)
b2 = BookInStock.new("isbn3", 234)
b3 = BookInStock.new("isbn22", 23)


p b1
p b2
p b3
puts b1
puts b2
puts b3

puts b1.isbn

puts BookInStock.to_s
