defmodule Finder do   

  def find(graph) do
    used_nodes = :ets.new(:used_nodes , [:set, :protected])
    merged_comp = :ets.new(:merged_comp , [:set, :protected])

    graph.adjacency_list |> Stream.with_index |> Enum.map( fn (n) ->
        {_, index} = n
        index |> bypass_to_deep(graph, index, used_nodes, merged_comp)
      end) |> Enum.uniq |> length |> IO.inspect
  end

  defp bypass_to_deep(node, graph, component_id, used_nodes, merged_comp) do
    if :ets.lookup(used_nodes, node) |> Enum.empty? do 
      :ets.insert(used_nodes, {node, component_id})
      {_, list} = graph.adjacency_list |> Enum.fetch(node)
      list |> Enum.map(fn (n) -> 
        bypass_to_deep(n, graph, component_id, used_nodes, merged_comp) 
      end) 
      |> Enum.reduce( fn (x, acc) -> acc ++ x end) 
      |> Enum.uniq
    else
      {_, comp} = :ets.lookup(used_nodes, node) |> Enum.fetch(0)
      if comp != component_id do 
        :ets.insert(merged_comp, {comp, component_id})
      end
      nil
    end 
  end
end
