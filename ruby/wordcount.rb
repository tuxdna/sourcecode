require 'wordcount_helpers'
wordlist = Array.new
while line = gets
  get_words(line).each do |word|
    wordlist.push(word)
  end
end


word_frequency = get_word_frequency(wordlist)
sorted = word_frequency.sort_by { |w,f| f }
sorted.reverse.each do |k,v|
  puts "word: #{k} occurs #{v} times"
end
