#!/usr/bin/ruby
def get_diff_time(h2, m2, h1, m1)
  t2 = Time.utc(Time.now.year, Time.now.month, Time.now.day, h2, m2)
  t1 = Time.utc(Time.now.year, Time.now.month, Time.now.day, h1, m1)
  s = t2 - t1
  diff_sec = s % 60
  s -= diff_sec

  m = s/60
  diff_min = m % 60
  m -= diff_min

  h = m / 60
  diff_hour = h % 24
  h -= diff_hour

  d = h / 24
  diff_day = d/30

  puts "Hour: %02d Minute: %02d Seconds: %02d"%[diff_hour, diff_min, diff_sec]
  puts "Time Difference %02d:%02d"%[diff_hour, diff_min]
end


str = ARGV[0]
str =~ /(\d+):(\d+)([a-zA-Z]+)/

remaining_string = $'
h1 = $1.to_i
m1 = $2.to_i
ampm1 = $3
if ampm1 =~ /pm/i
  h1+=12
end

remaining_string =~ /(\d+):(\d+)([a-zA-Z]+)/
h2 = $1.to_i
m2 = $2.to_i
ampm2 = $3
if ampm2 =~ /pm/i
  h2+=12
end

puts h1
puts m1
puts h2
puts m2

get_diff_time( h2, m2, h1, m1 )
