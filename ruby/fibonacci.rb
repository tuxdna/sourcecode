def fib_upto(max)
  i1, i2 = 1, 1
  while i1 < max
    yield i1
    i1, i2 = i2, i1+i2
  end
end

fib_upto(1000) { |f| print f, " " }
puts


