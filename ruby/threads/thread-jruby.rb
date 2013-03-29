require 'net/http'
pages = %w( www.rubycentral.com slashdot.org www.google.com www.redhat.com www.yahoo.com www.bing.com facebook.com twitter.com)
threads = []
index = 1
for page_to_fetch in pages
  threads << Thread.new(page_to_fetch, index) do |url, thread_id|
    def do_print(tid, m)
      print "Thread #{tid} at #{Time.now.to_f} - #{m}\n"
    end
    sleep_time = rand(2)
    do_print thread_id, "Created... sleeping for #{sleep_time}s"
    sleep sleep_time
    h = Net::HTTP.new(url, 80)
    do_print thread_id, "Fetching: #{url}"
    resp = h.get('/')
    sleep_time = thread_id < 5 ? thread_id : 5
    do_print thread_id, "Sleeping for #{sleep_time}s"
    sleep sleep_time
    do_print thread_id, "Got #{url}: #{resp.message}"
  end
  index += 1
end
threads.each {|thr| thr.join }
