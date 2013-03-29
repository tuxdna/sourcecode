class BookInStock
  @@total = 0
  attr_reader :date, :isbn, :price
  # attr_accessor :var1
  def initialize(isbn, price)
    @isbn = isbn
    @price = Float(price)
    @@total += 1
  end
  def to_s
    "ISBN: #{@isbn}, Price: #{@price}"
  end
  def total
    @@total
  end
  def var1=(var1)
    @var1=var1
  end
end


require 'csv'

class CsvReader
  def initialize
    @books_in_stock = []
  end
  def read_in_csv_data(csv_file_name)
    entries = CSV.read(csv_file_name)
    entries.shift
    entries.each do |e|
      @books_in_stock << BookInStock.new(e[1], e[2])
    end
  end
  def total_value_in_stock
    sum = 0.0
    @books_in_stock.each { |b|  sum+=b.price }
    sum
  end
  def number_of_each_isbn
  end
end
