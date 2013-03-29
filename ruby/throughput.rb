#!/usr/bin/ruby -w

# NOTE: 
#  all space units are in GBs
#  all time units are in ms ( milliseconds )
num_cores = 4 # number of cores in the processor
ram_size = 8 # GB
on_disk_data_size = 30 # GB
hit_ratio = ram_size / on_disk_data_size.to_f
seek_time_from_ram = 100 # milliseconds
seek_time_from_disk = 400 # milliseconds
##
#  Average lagency on 256kbit/s network would be 60-110ms
## http://en.wikipedia.org/wiki/Network_performance#Web_surfing
#
## calculate network latency
# $ traceroute google.com
# >> s = <<EOD
# 64 bytes from bom04s01-in-f14.1e100.net (173.194.36.14): icmp_req=17 ttl=57 time=8.68 ms
# ... OUTPUT SKIPPED ...
# 64 bytes from bom04s01-in-f14.1e100.net (173.194.36.14): icmp_req=18 ttl=57 time=37.8 ms
# EOD
# >> time = s.split("\n").map{|l| l.split()[-2].split("=")[-1].to_i }
# => [8, 24, 36, 69, 67, 70, 49, 31, 97, 13, 61, 84, 15, 11, 139, 60, 8, 37]
# >> time.inject(:+) / time.length.to_f
# => 48.8333333333333
network_latency = 60 # milliseconds

## determine application server response time
# webrick processes a request in 43ms ( for some random request )
server_processing_time = 43 # milliseconds

# calculate seek time for random queries on an average
# seek_time_from_ram + ( 1 - hit_ratio) * seek_time_from_disk
average_seek_time = seek_time_from_ram + (1 - hit_ratio) * seek_time_from_disk

request_response_time = server_processing_time + network_latency + average_seek_time

puts "Average Seek Time: #{average_seek_time}ms"
puts "Response Time: #{request_response_time}ms"



#          number of users
# rps = ---------------------------- x (requests per user per page)
#        response_time + think_time

#
# Assuming think time for a user is 15 seconds = 15000ms
think_time = 15000
num_users = 5
requests_per_user_per_page = 10
rps = (num_users / (1000*(request_response_time + think_time))) * ( requests_per_user_per_page )


puts "Requests per second: #{rps}"
