#!/usr/bin/ruby

class Package
  attr_accessor :visible
  def initialize(visibility=false)
    self.visible = visibility
  end
  def make_visible!(visibility)
    puts "(before notnot) visibility: #{visibility}"
    visibility = !!visibility # convert to true / false
    puts "(after notnot) visibility: #{visibility}"
    puts "(before update) visible: #{self.visible}"
    self.visible = visibility
    puts "(after update) visible: #{self.visible}"
  end
end


def fun1(params)
  visibility = params[:package][:visible]
  puts "visibility in function: #{visibility}"
  package = Package.new(true)
  package.make_visible!(visibility)
end

params = {:package => {:visible => false}}
fun1(params)
