defmodule Graph do
  defstruct nodes_count: 0, adjacency_list: []

  def load(file_path) do
    input_file = File.open!(file_path, [:read, :utf8]) 

    {nodes_count, _} = Integer.parse IO.read(input_file, :line)


    adjacency_list = 0..(nodes_count - 1) |> Enum.map(fn (x) -> read_line_from_file(input_file) end)

    %Graph{nodes_count: nodes_count, adjacency_list: adjacency_list}
  end

  def print(graph) do 
    IO.puts "Nodes count - #{graph.nodes_count}"
    graph.adjacency_list |> Enum.each(fn (line) -> print_adjacency_list_line(line) end)
  end

  defp print_adjacency_list_line(line) do
    line |> Enum.each(fn (x) -> IO.inspect x end)
    #line |> Enum.reduce("", fn (i, acc) -> acc <> "#{i} " end) |> IO.puts
  end

  defp read_line_from_file(input_file) do
    IO.read(input_file, :line) |> String.split(" ") |> Enum.map(fn (x) -> parse_node(x) end) |> Enum.filter(fn (x) -> is_integer(x) end)
  end

  defp parse_node(str) do
    case Integer.parse(str) do
      {i, _} -> i 
      _ -> nil
    end    
  end 
end
    