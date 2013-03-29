accept_input = true
while accept_input
  line = gets.chomp
  break if line == "quit"
  puts line
end
