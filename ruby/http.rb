require 'net/http'

class MyHttp
  include Net::HTTPHeader
  attr_accessor :header
  def initialize
    self.initialize_http_header({})
  end
end


# m = MyHttp.new
# m.add_field "HEADER", "Value"
# p m.to_hash
