class Parent
  def say_hello
    puts "Hello from #{self}"
  end
end

class Child < Parent
end

parent = Parent.new
child = Child.new

parent.say_hello
child.say_hello
