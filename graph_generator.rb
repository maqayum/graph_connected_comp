
puts 'Enter components count'
comp_count = gets.chomp
comp_count = comp_count.to_i

puts 'Enter component size'
comp_size = gets.chomp
comp_size = comp_size.to_i

puts 'Enter output file name'
filename = gets.chomp

nodes_count = comp_count * comp_size

File.open(filename, 'w') do |file|
  file.puts nodes_count

  comp_count.times do |i|
    start_node_number = i * comp_size    
    comp_size.times do |j|
      node = start_node_number + j
      str = ""
      comp_size.times do |k|
        ad_node = start_node_number + k
        if ad_node != node
          str += "#{ad_node} "
        end
      end

      file.puts str
    end
  end
end