
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
    comp_size.times do |j|
      node = (i + 1) * j
      str = ""
      comp_size.times do |k|
        ad_node = (i + 1) * k
        if ad_node != node
          str += "#{ad_node} "
        end
      end

      file.puts str
    end
  end
end