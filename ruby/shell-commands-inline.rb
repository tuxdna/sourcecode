#!/usr/bin/ruby

directorylist = %x[find . | sort]
directorylist.each do |f|
  print f
end

