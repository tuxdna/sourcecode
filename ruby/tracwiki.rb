#!/usr/bin/ruby
require 'rubygems'
require 'spreadsheet'
xlsfile = ARGV[0] if ARGV.length > 0
sheetname = ARGV[1] if ARGV.length > 1
exit unless xlsfile
book = Spreadsheet.open xlsfile
sheet1 = book.worksheet sheetname

sheet1.each_with_index do |r,i|
  s = nil
  if i==0
  then
    s = "||"+r.map do |k|
      "'''#{k}'''"
    end.join("||")+"||"
  else
    s= "||"+r.map do |k|
      if k.is_a?(Float)
        k = k.to_i
      else
        k
      end
    end.join("||")+"||" 
  end
  puts s
end
