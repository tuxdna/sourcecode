def run_block
  if block_given?
    yield
  else
    puts "no block given"
  end
end

run_block do
  puts "hello world"
end

run_block
