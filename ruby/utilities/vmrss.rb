#!/usr/bin/env ruby
def vmrss
  File.readlines('/proc/self/status').select do |l| 
    l =~ /VmRSS/
  end.first.split[1..-1].join(" ")
end

# puts "My current memory consumption: #{vmrss}"
