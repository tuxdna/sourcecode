require 'rubygems'
require 'pp'
raise if RUBY_VERSION != "1.8.7"
class MyClass
  attr_accessor :num
  def initialize(i)
    self.num = i
    capture_call(:a, :b) { before_call() }
  end

  def a()
    puts "a()"
  end

  def b()
    puts "b()"
  end

  def c()
    puts "c()"
  end


  private
  def before_call()
    puts "before_call() for num: #{self.num}"
  end
  def capture_call(*names)
    names.each do |name|
      m = self.class.instance_method(name)
      self.class.send(:define_method, name) do | *args, &block |
        yield
        m.bind(self).call(*args, &block)
      end
    end
  end
end

obj = MyClass.new(1)
obj.c
obj.a
obj.b
MyClass.new(2).a
MyClass.new(3).b
