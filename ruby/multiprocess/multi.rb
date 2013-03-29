#!/usr/bin/ruby

puts "In parent process. Pid = #{$$}"

fork do
  puts "In child process. Pid = #{$$}"
  exit 0
end

begin
  puts "Waiting for child processes" 
  pid = Process.wait
rescue Errno::ECHILD => e
  puts e
end
