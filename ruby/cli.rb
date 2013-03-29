puts "Script Name \$0 = #{$0}"
puts "__FILE__ = #{__FILE__}"

ARGV.each_with_index { |a,i| printf("Argument %d = %s\n", i, a) }
