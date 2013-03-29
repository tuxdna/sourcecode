require 'books'
require 'test/unit'

class TestBooks < Test::Unit::TestCase
  def test_book
    b1 = BookInStock.new("isbn1", 2)
    b1.var1 = "this is var1"
    begin
      puts b1.var1
    rescue NoMethodError => e
      # pass
    else
      # test failed
      raise
    end
  end

  def test_csv_reader
    reader = CsvReader.new
    reader.read_in_csv_data("books.csv")
    puts "Total books in stock: #{reader.total_value_in_stock}"

  end
end
