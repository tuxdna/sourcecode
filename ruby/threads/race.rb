if ARGV.length >= 1
  max_threads = ARGV[0].to_i
else
  max_threads = 10
end
count = 0
threads = []
max_threads.times do |i|
  threads[i] = Thread.new do
    sleep(rand(0.1))
    Thread.current["mycount"] = count
    sleep(rand(1))
    count += 1
  end
end
counts_h = Hash.new(0)
threads.each {|t| t.join; c = t["mycount"]; counts_h[c] += 1 }
counts_h.keys.sort.select{|e| counts_h[e] > 1 }.each { |k| print k, ", " }
# threads.sort! {|a,b| a["mycount"] <=> b["mycount"] }
# threads.each {|t| print t["mycount"], ", " }


puts "count = #{count}"
