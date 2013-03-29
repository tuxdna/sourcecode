#!/usr/bin/ruby 

# a basic block
def call_block
  puts "start of method"
  yield
  yield
  puts "end of method"
end

call_block { puts "hi" }                                                                          


# passing arguments
def who_says_what
  yield("this", "that")
  yield("foo", "bar")
end

who_says_what { |fn, ln| puts "Hello #{fn.capitalize} #{ln.capitalize}!" }

# iterating over elements
animals = %w{ant bee cat dog elk}
animals.each { |a| puts a }
