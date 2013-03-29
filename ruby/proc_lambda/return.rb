def run_a_proc(p)
  puts "before the call"
  p.call
  puts "after the call\n\n"
end

def our_program
  run_a_proc Proc.new { puts "i am a proc"; return }
  run_a_proc lambda { puts "i am a lambda"; return }
end

our_program

run_a_proc lambda { puts "i am a lambda"; return }
run_a_proc Proc.new { puts "i am a proc"; return }

