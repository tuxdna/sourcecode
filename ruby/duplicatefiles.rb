#!/usr/bin/ruby

## This file finds all the duplicate files form a directory given
## at the command line.
## Released under the GPLv2
## Copyright (C) tuxdna(at)gmail(dot)com

require 'digest/md5'

## novice use of exceptions
begin
  throw nil if ARGV.length == 0
rescue
 print "Usage: ", $0, " \n"
 exit 1
end

directory = ARGV[0]
print "Name of directory given is :", directory, "\n"

## do not proceed if it is not a directory
exit 1 if File.file?(directory)

puts "Getting the list recursively, for all the files and sub-directories."
filelist = Dir[directory+"/**/*"]

puts "Now scanning the files: "
puts "Determining file size and Filtering the directories:"

sizehash = Hash.new { |h,k| h[k] = [] }
filelist.each do |filename|
 if File.file?(filename)
  sizehash[File.size(filename)].push(filename)
 end
end

## prune those entries which do not have same size
sizehash.delete_if { |k,v| v.length<=1 }
duplicates_md5 = Hash.new { |h,k| h[k] = [] }
  sizehash.each do | size, files |
  files.each do |filename|
     md5sum = Digest::MD5.new( File.new(filename).read )
     ## Necessary to do this because md5sum is an object of class Digest::MD5
     ## and we need a string for a key!!
     md5sum = md5sum.to_s
     duplicates_md5[md5sum].push(filename)
  end
end

## prune those entries which do not have same md5 hash value 
duplicates_md5.delete_if { |k, v| v.length <= 1 }
## print the files if we find duplicates now!
duplicates_md5.each do |h, files|
  puts "Following files match: "
  files.each { |f| puts f }
  puts
end
exit 0
