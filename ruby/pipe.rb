#!/usr/bin/ruby
pipe = IO.popen("dwdiff --diff-input", "w+")
str = File.read("/tmp/no-nonsense-feature.patch")

pipe.puts str
pipe.close_write
puts pipe.read
