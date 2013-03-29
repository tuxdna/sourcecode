require 'digest/sha1'
require 'vmrss'

puts "Current memory consumption: #{vmrss}"
sha_sum = Digest::SHA1.new
filename = '/proc/cpuinfo'
if ARGV.length >=1
  filename = ARGV[0]
end

f = File.open(filename)
while k = f.read(1024*1024)
  sha_sum.update(k)
end
puts "Current memory consumption: #{vmrss}"
f.close
puts "Current memory consumption: #{vmrss}"
puts sha_sum
