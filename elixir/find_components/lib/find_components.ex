defmodule FindComponents do
  def main(argv) do
    argv |> parse_args |> process
  end

  def process(options) do 
   options[:graph] |> Graph.load |> Finder.find(Integer.parse options[:processes]) |> IO.inspect
  end 

  defp parse_args(argv) do
    {options, _, _} = OptionParser.parse(argv, 
      switches: [graph: :string, processes: :string]
    )
    options
  end 
end