#!/usr/bin/ruby
def factorial(number)
  factorial_value = 1
  while number > 1
    factorial_value = factorial_value * number
    number = number - 1
  end
  return factorial_value
end

def fact(number)
  if number > 1
    return number*fact(number-1)
  else
    return number
  end
end

class Factorial
  def initialize(num)
    @n = num
  end
  def fact
    factorial(@n)
  end
end

# puts "Please enter a number below:"
# number = gets.chomp.to_i

# puts "You entered: #{number}"
# factorial_value = 1
# while number > 1
#   factorial_value = factorial_value * number
#   number = number - 1
# end

# puts "Your factorial value is: #{fact(number)}"

f1 = Factorial.new(5)
f2 = Factorial.new(7)
f3 = Factorial.new(10)

puts f1.fact
puts f2.fact
puts f3.fact

class My_class
end
