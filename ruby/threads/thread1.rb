require 'thread'

def inc(n)
  n+1
end

sum = 0
mutex = Mutex.new
threads = (1..10).map do
  Thread.new do
    1000.times do
      mutex.synchronize do
        sum = inc(sum)
      end
    end
  end
end

threads.each(&:join)
p sum    
