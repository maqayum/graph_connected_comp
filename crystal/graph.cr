class Graph 
  property :adjacency_matrix

  def floid
    adjacency_matrix.each_index do |k| 
      adjacency_matrix.each_index do |i|
        row.each_index do |j|
          adjacency_matrix[i, j] = [adjacency_matrix[i, k], adjacency_matrix[k, j]].min
        end
      end
    end
    adjacency_matrix
  end

  def connected? 
    matrix = floid 
  end

  class Loader
    def initialize(file_path : String)
      @file_path = file_path
    end

    def load
      lines = File.read_lines @file_path

      adjacency_matrix = []

      lines.delete_at(0).each do |line|
        adjacency_matrix << line.slice(' ').map {|el| el.to_i}
      end

      graph = Graph.new
      graph.adjacency_matrix = adjacency_matrix
      graph
    end
  end 
end 