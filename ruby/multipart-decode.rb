#!/usr/bin/ruby1.8

## decode the multi-part messages

require 'rubygems'
require 'mail'

if ARGV[0].nil?
  puts "No filename for processing"
else
  mail = Mail.read(ARGV[0])
  print mail.parts[0].decoded
end
