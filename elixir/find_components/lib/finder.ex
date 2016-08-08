defmodule Finder do   

  def find(graph) do
    used_nodes = :ets.new(:used_nodes , [:set, :protected])

    0..(graph.nodes_count - 1) |> Enum.map( fn (n) ->
        n |> bypass_to_deep(graph, used_nodes)
      end) |> Enum.reject(&(is_nil(&1))) |> IO.inspect |> normalize |> Enum.count
  end

  defp normalize(components) do   
    removed_comp_ids = [-1]
    components |> Enum.reduce([], fn (x, acc) -> 
      if x.linked |> Enum.count > 0 do
        if x.linked |> Enum.all?(fn (l) -> removed_comp_ids |> Enum.member?(l) end) do
          acc ++ [x]
        else
          removed_comp_ids = removed_comp_ids ++ [x.id]
          acc
        end
      else 
        acc ++ [x]
      end
    end)
  end 

  defp bypass_to_deep(node, graph, used_nodes, component) do
    component = component |> Map.update(:nodes, [], &(&1 ++ [node]))
    if :ets.lookup(used_nodes, node) |> Enum.empty? do 
      :ets.insert(used_nodes, {node, component.id})


      {_, list} = graph.adjacency_list |> Enum.fetch(node)

      list |> Enum.map(fn (n) -> 
        bypass_to_deep(n, graph, used_nodes, component)       
      end) 
      |> Enum.reduce( fn (x, acc) ->         
        nodes  = Enum.concat(x.nodes, acc.nodes) |> Enum.uniq
        linked = Enum.concat(x.linked, acc.linked) |> Enum.uniq
        %Component{id: acc.id, nodes: nodes, linked: linked}
      end)        
    else
      {_, cache} = :ets.lookup(used_nodes, node) |> Enum.fetch(0)
      {_, comp} = cache
      if comp != component.id && !(Enum.member?(component.linked, comp)) do 
        component |> Map.update(:linked, [], &(&1 ++ [comp]))
      else
        component
      end      
    end 
  end 

  defp bypass_to_deep(node, graph, used_nodes) do
    if :ets.lookup(used_nodes, node) |> Enum.empty? do 
      bypass_to_deep node, graph, used_nodes, %Component{id: node}
    end
  end
end
