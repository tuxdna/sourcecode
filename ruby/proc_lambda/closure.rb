def run_proc(p)
  p.call
end

name = "tuxdna"
print_a_name = Proc.new { puts name }
run_proc print_a_name

def multiple_generator(m)
  lambda do |n|
    n * m
  end
end

doubler = multiple_generator(2)
tripler = multiple_generator(3)

puts doubler[5]
puts tripler[10]

name = "sansari"

run_proc print_a_name
