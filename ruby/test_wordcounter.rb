require 'wordcount_helpers'
require 'test/unit'

class TestWordCount < Test::Unit::TestCase
  def test_word_list
    assert([], get_words(""))
    assert([], get_words(", , . # #"))
    assert([], get_words("1234"))
    assert([], get_words("     "))
  end
end
