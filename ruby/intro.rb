def say_goodnight(name)
  result = "Good night, #{name.capitalize}"
  return result
end

def callb
  puts 'start'
  yield 'sansari'
  yield 'tuxdna'
  puts 'end'
end

callb { |name| puts say_goodnight(name) }

# line = gets

puts "You gave #{ARGV.size} arguments"
p ARGV
