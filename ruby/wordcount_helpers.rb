def get_words(string)
  string.scan(/[\w']+/)
end

def get_word_frequency(wordlist)
  word_frequency = Hash.new(0)
  wordlist.each do |word|
    word_frequency[word] += 1
  end
  word_frequency
end


# wordlist = Array.new
# while line = gets
#   get_words(line).each do |word|
#     wordlist.push(word)
#   end
# end


# word_frequency = get_word_frequency(wordlist)
# sorted = word_frequency.sort_by { |w,f| f }
# sorted.reverse.each do |k,v|
#   puts "word: #{k} occurs #{v} times"
# end
# # p sorted
