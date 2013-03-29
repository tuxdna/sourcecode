class Person
  include Comparable
  @@total_instances = 0
  # this is the constuctor
  # def __init__ in Python
  # Person() in Java / C++
  def initialize(name, address)
    @name = name
    @address = address
    @@total_instances += 1
  end
  def say_hello
    printf "I am %s, and I live in: %s\n", @name, @address
  end
  def Person.how_many
    @@total_instances
  end
  def name
    @name
  end
  def <=>(other) 
    @name.length <=> other.name.length
  end
  def to_s
    "Name: #{@name} stays at #{@address}"
  end
end

class Employee < Person
  def initialize(name, address, company)
    super(name, address)
    @company = company
  end
  def say_hello
    super
    printf "I work at %s.\n", @company
  end
end

p1 = Person.new("Saleem", "Magarpatta")
p2 = Person.new("Matz", "Japan")
p1.say_hello
p2.say_hello
printf "Persons instantiated so far: %d\n\n", Person.how_many

e1 = Employee.new("Rambo", "Italy", "Hollywood")
e1.say_hello
printf "Persons instantiated so far: %d\n\n", Person.how_many

module College
  class Student < Person
    ## no added functionality here
  end
end

e4 = College::Student.new("Messi", "Argentina")
e4.say_hello
printf "Persons instantiated so far: %d\n\n", Person.how_many

names = %w{Saleem Matz Messi Ronaldinho}
addresses = %w{Magarpatta Japan Argentina Brazil}

persons = names.zip(addresses).map do |n,a|
  Person.new(n,a)
end
puts "Before sorting is done"
puts persons[0]
p persons[0]
persons = persons.sort
puts "After sorting is done"
p persons
