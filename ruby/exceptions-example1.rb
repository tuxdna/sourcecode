class InstallFailed < Exception; end
class BuildFailed < Exception; end
class CleanupFailed < Exception; end

class OtherFailure < Exception
  attr :reason
  def initialize(reason)
    @reason = reason
  end
end

begin
  case ARGV[0]
  when "i"
    raise InstallFailed.new()
  when "b"
    raise BuildFailed.new()
  when "s"
    raise CleanupFailed.new()
  when "o"
    raise OtherFailure.new(ARGV[1])
  end
rescue InstallFailed => e
  puts "install failed"
rescue BuildFailed => e
  puts "build failed"
rescue CleanupFailed => e
  puts "cleanup failed"
rescue OtherFailure => e
  puts "something bad has happened: #{e.reason}"
ensure
  puts "Inside ensure block. Doing cleanup work."
end
