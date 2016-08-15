class Graph 
  property :adjacency_matrix

  def initialize(adjacency_matrix : Array(Array(Int32)) )
    @adjacency_matrix = adjacency_matrix
  end


  def floyd
    adjacency_matrix.each_index do |k| 
      adjacency_matrix.each_with_index do |row,   i|
        row.each_index do |j|
          tmp = 
          adjacency_matrix[i][j] = [(adjacency_matrix[i][k] + adjacency_matrix[k][j]), adjacency_matrix[i][j]].min
        end
      end
    end
    adjacency_matrix
  end

  def nodes_count 
    adjacency_matrix.size
  end

  def connected? 
    matrix = floyd
    nodes_count = nodes_count
    matrix.all? do |row|
      row.all? {|el| el < nodes_count * 2}
    end
  end

  class Loader
    def initialize(file_path : String)
      @file_path = file_path
    end

    def load
      lines = File.read_lines @file_path

      nodes_count = lines.delete_at(0).to_i

      adjacency_matrix = (0..(nodes_count - 1)).map do |i|
        (0..(nodes_count - 1)).map do |j| 
          i == j ? 0 : (nodes_count * 2)
        end
      end

      lines.each_with_index do |line, index|
        line.gsub(" \n", "").split(' ').each {|el| adjacency_matrix[index][el.to_i] = 1}
      end

      Graph.new adjacency_matrix
    end
  end 
end 