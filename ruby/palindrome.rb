def palindrome?(s)
  a = s.gsub(/[\W]/, "").downcase
  true if a.reverse == a
  false
end

puts "YES" if palindrome?("This, is si :SiHT")
puts "YES" if palindrome?("This")
