require 'shellwords'

module CommandUtils
  # executes the command and returns the files where 
  # stdout and stderr is written to in this format
  # [:stdout => stdout_file, :stderr => stderr_file, :success => success_status]

  def self.run_command(cmd, options={})
    raise if cmd.nil?
    raise unless cmd.is_a?(Array) or cmd.is_a?(String)

    if cmd.is_a?(Array)
      cmd = cmd.shelljoin
    end


    null_file = '/dev/null'
    serr = options[:stderr] || null_file
    sout = options[:stdout] || null_file
    verbose = options[:verbose] || nil
    combined_output = options[:combined_output] || nil

    if combined_output
      cmd = "#{cmd} 2>&1"
    else
      cmd = "#{cmd} 2>#{serr}" if serr
    end
    
    cmd = "#{cmd} 1>#{sout}" if sout

    if verbose
      puts "executing: #{cmd.inspect}"
    end

    retval = nil
    status = system(cmd)
    retval = {
      :stdout => sout == null_file ? nil : sout,
      :stderr => serr == null_file ? nil : serr,
      :success => status
    }
    if verbose
      p retval
    end

    return retval
  end
end
