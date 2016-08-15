require "./graph.cr"
require "option_parser"

treads = 1

OptionParser.parse! do |parser|
  parser.on("-g NAME", "--graph=FILE", "Path to graph data") { |path| file_name = path }
  parser.on("-t TREADS", "--treads=TREADS", "Treads count") { |tr| treads = tr.to_i }
  parser.on("-h", "--help", "Show this help") { puts parser }
end

p Graph::Loader.load(file_name).connected?
