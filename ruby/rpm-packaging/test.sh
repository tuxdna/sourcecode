PREFIX=$HOME
export GEM_HOME=$PREFIX/lib/ruby/gems/1.8
export RUBYLIB=$PREFIX/lib/ruby:$PREFIX/lib/site_ruby/1.8
ruby setup.rb all --prefix=$PREFIX
