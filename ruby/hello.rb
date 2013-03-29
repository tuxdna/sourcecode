puts "Please enter your name"
name = gets.chomp
puts "Please enter you grade"
grade = gets.chomp
puts "Hello #{name}"
# if grade == "A"
#    puts "Excellent"
# elsif grade == "B"
#    puts "Good"
# else 
#   puts "Bad"
# end

case grade
when ("A".."C")
  puts "Just passed"
else
 puts "failed"
end

