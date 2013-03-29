def get_lambda
  name = "tuxdna"
  return Proc.new { name }
end

def hello
  puts get_lambda.call
end

hello
