INPUT = $< 
begin
  while l = INPUT.readline
    print l
  end
rescue EOFError => e
  exit 0
end
