module MyModule
  PI = 3.14
end


class MyClass
  include MyModule
end


module Debug
  def whoami?
    "#{self.class.name} (\##{self.object_id}: #{self.to_s})"
  end

  def self.abc
    puts "ths is abc"
  end

  def introduce_var
    @var = 123
  end
end

class Phonograph
  include Debug
end

class EightTrack
  include Debug
end

array = [Phonograph.new, EightTrack.new]
array.each { |e| puts e.whoami? }
# array.each { |e| puts (e.class).abc }
