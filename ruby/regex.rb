#!/usr/bin/ruby
# Regular Expressions in Ruby

def show_regexp(string, pattern)
  match = pattern.match(string)
  if match
    "#{match.pre_match}->#{match[0]}<-#{match.post_match}"
  else
    "no match"
  end
end


exit

# # replace first 'Perl' with 'Ruby'
# line.sub(/Perl/, 'Ruby')
# # replace every 'Python' with 'Ruby'
# line.gsub(/Python/, 'Ruby') 

while line = gets
  if line =~ /(Perl|Python)/
    print line
  end
end
