#!/usr/bin/ruby

require 'rubygems'
require 'rss/1.0'
require 'rss/2.0'
require 'open-uri'
require 'json'

url = "http://tuxdna.wordpress.com/feed/"
content = ""
open(url) do |s|
  content = s.read() 
end
rss = RSS::Parser.parse(content, false)

items = []
rss.items.each do |i|
  items.push(
             {
               :title => i.title,
               :link => i.link,
               :description => i.description,
               :pub_date => i.pubDate
             }
           )
end

data = {
  :title => rss.channel.title,
  :link => rss.channel.link,
  :description => rss.channel.description,
  :items => items
}


puts data.to_json
