#!/usr/bin/ruby
require 'set'

# s1 and s2 are anye numerable that supports min and max
def range_intersect?(s1, s2)
  s1range = s1.to_a.min..s1.to_a.max
  s2range = s2.to_a.min..s2.to_a.max
  return s1range.include?(s2range.first) || s2range.include?(s1range.first)
end

# s1 = Set.new([1,2,3,4])
# s2 = Set.new([4,5,6,7])
# s3 = Set.new([5,6,7])

s1 = Set.new(['1','2','3','4'])
s2 = Set.new(['4','5','6','7'])
s3 = Set.new(['5','6','7'])

p range_intersect?(s1,s2)
p range_intersect?(s2,s1)
p range_intersect?(s2,s3)
p range_intersect?(s1,s3)

