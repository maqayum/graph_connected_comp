require 'benchmark'

puts Benchmark.measure { `./find_comps.out graph.txt` }