require 'benchmark'

Benchmark.bm do |x|
  x.report { `find  /usr` }
end
