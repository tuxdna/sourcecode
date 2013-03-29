str = <<EOD
The buildings of Nuffield College, one of the colleges of the University of Oxford, are to the west of the city centre of Oxford, England, on the former site of the largely disused basin of the Oxford Canal.
Nuffield College was founded in 1937 after a donation to the university by the car manufacturer Lord Nuffield.
He rejected the initial designs of the architect Austen Harrison, which were heavily influenced by Mediterranean architecture, describing them as "un-English".
Harrison then aimed for "something on the lines of Cotswold domestic architecture", as Nuffield wanted.
The college was built to the revised plans between 1949 and 1960.
During construction, the tower, about 150 feet (46 m) tall, was redesigned to hold the college's library.
Reaction to the architecture has been largely unfavourable.
It has been described as "Oxford's biggest monument to barren reaction" and "a hodge-podge from the start".
However, the architectural historian Sir Nikolaus Pevsner thought that the tower helped the Oxford skyline and predicted that it would "one day be loved".
The writer Simon Jenkins doubted Pevsner's prediction, though, saying that "vegetation" was the "best hope" for the tower, and for the rest of the college too.
EOD

str.split("\n").each do |line|
  r_output = ( line =~ /(of|to) the/m )
  p [r_output, line[r_output..-1] ] if not r_output.nil?
end


