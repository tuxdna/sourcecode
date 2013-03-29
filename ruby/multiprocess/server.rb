#!/usr/bin/ruby
# reference: http://tomayko.com/writings/unicorn-is-unix

# simple preforking echo server in Ruby
require 'socket'

# Create a socket, bind it to localhost:4242, and start listening.
# Runs once in the parent; all forked children inherit the socket's
# file descriptor.
acceptor = Socket.new(Socket::AF_INET, Socket::SOCK_STREAM, 0)
address = Socket.pack_sockaddr_in(4242, '127.0.0.1')
acceptor.bind(address)
acceptor.listen(10)

# Close the socket when we exit the parent or any child process. This
# only closes the file descriptor in the calling process, it does not
# take the socket out of the listening state (until the last fd is
# closed).
#
# The trap is guaranteed to happen, and guaranteed to happen only
# once, right before the process exits for any reason (unless
# it's terminated with a SIGKILL).
trap('EXIT') { acceptor.close }

# Fork you some child processes. In the parent, the call to fork
# returns immediately with the pid of the child process; fork never
# returns in the child because we exit at the end of the block.
3.times do
  fork do
    # now we're in the child process; trap (Ctrl-C) interrupts and
    # exit immediately instead of dumping stack to stderr.
    trap('INT') { exit }

    puts "child #$$ accepting on shared socket (localhost:4242)"
    loop {
      # This is where the magic happens. accept(2) blocks until a
      # new connection is ready to be dequeued.
      socket, addr = acceptor.accept
      socket.write "child #$$ echo> "
      socket.flush
      message = socket.gets
      socket.write message
      socket.close
      puts "child #$$ echo'd: '#{message.strip}'"
    }
    exit
  end
end

# Trap (Ctrl-C) interrupts, write a note, and exit immediately
# in parent. This trap is not inherited by the forks because it
# runs after forking has commenced.
trap('INT') { puts "\nbailing" ; exit }

# Sit back and wait for all child processes to exit.
Process.waitall
