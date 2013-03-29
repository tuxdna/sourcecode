require 'rubygems'
require 'pp'
require 'yaml'
app_config = YAML.load(File.read("app_config.yml"))
pp app_config
