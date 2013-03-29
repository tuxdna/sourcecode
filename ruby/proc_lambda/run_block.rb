def run_block
  # implicitly pass a block to Proc.new
  p = Proc.new
  p.call
end

run_block do
  puts "Hello"
end

