class Person
  include Comparable
  attr_reader :name
  def initialize(name)
    @name = name
  end

  def to_s
    "#{@name}"
  end

  def <=>(other)
    self.name <=> other.name
  end
end

names = %w{harry barry sally bill gill hen}
persons = names.each.map { |n| Person.new(n) }

persons.sort!
p persons


  
