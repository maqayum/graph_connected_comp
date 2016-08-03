#include "graph_loader.h"
#include "graph.h"
#include <sstream>

GraphLoader::GraphLoader(std::string file_path){
  this->file_path = file_path;
};

Graph GraphLoader::load() {
  std::ifstream in;

  in.open(this->file_path);

  int nodes_count;
  in >> nodes_count;

  std::string tmp;
  std::getline(in, tmp);

  Graph graph;
  graph.nodes_count = nodes_count;

  std::vector< std::vector<int> > adjacency_list;

  for(int i = 0; i < nodes_count; ++i){
    std::getline(in, tmp); 

    std::istringstream string_stream;

    string_stream.str(tmp);

    std::vector<int> list;

    while (string_stream.good()){
      int j;
      string_stream >> j;
      list.push_back(j);
    }

    adjacency_list.push_back(list);
  };
  graph.adjacency_list = adjacency_list;
  return graph;
};
