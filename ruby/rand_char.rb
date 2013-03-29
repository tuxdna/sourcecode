$VALID_CHARS = ('0'..'9').to_a + ('A'..'Z').to_a + ('a'..'z').to_a
def rand_char
  $VALID_CHARS.choice
end

STDOUT.sync = true
sleep_time = 0
[10, 100, 1000, 10000, 100000].each do |max|
  s = (1..max).map{ rand_char }.join
  msg = "#{max} characters, sleeping for #{sleep_time}s"
  print "Attempting: #{msg} - "
  puts "#{s} : #{max} characters, sleeping for #{sleep_time}s"
  # STDOUT.flush
  STDERR.flush
  STDERR.puts "DONE: #{msg}"
  sleep sleep_time
end
