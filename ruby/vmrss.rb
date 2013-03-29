#!/usr/bin/env ruby
def vmrss
    File.readlines('/proc/self/status').select {|l| l =~ /VmRSS/}.first.split[1..-1].join(" ")
end

puts "My current memory consumption: #{vmrss}"
