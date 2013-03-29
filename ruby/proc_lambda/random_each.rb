class Array
  def random_each
    shuffle.each do |e1|
      yield e1
    end
  end
  def random_each2(&b)
    p b
    shuffle.each do |e1|
      b.call e1
    end
  end
end

array = [1,2,3,4,5]

puts array.random_each{ |e| e }.join(", ")
puts array.random_each2{ |e| e }.join(", ")
