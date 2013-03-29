module Logger
  def log(msg)
    STDERR.puts Time.now.strftime("%H:%M:%S") + "#{self} (#{msg})"
  end

  def self.log(msg)
    STDERR.puts Time.now.strftime("%H:%M:%S") + "#{self} (#{msg})"
  end
  puts "#{self} LOGGER"
end

class Song
  include Logger
end

class Album
  include Logger
end

s = Song.new.extend Logger
s.log("Song created")
Song.log("Hello")
# a = Album.new
# a.log("Album created")
