#include "graph_loader.h"
#include "graph.h"
#include "utils.h"
#include <sstream>

GraphLoader::GraphLoader(std::string file_path){
  this->file_path = file_path;
};

Graph GraphLoader::load() {
  std::ifstream in;

  in.open(this->file_path.c_str());

  int nodes_count;
  in >> nodes_count;

  std::string tmp;
  std::getline(in, tmp);

  Graph graph;
  graph.nodes_count = nodes_count;

  std::vector< std::vector<int> > adjacency_matrix;

  for(int i = 0; i<nodes_count; ++i){
    std::vector<int> list;
    for(int j = 0; j<nodes_count; ++j){
      int el;
      if (i==j){
        el = 0;
      }
      else{
        el = nodes_count * 2;
      }
      list.push_back(el);
    }
    adjacency_matrix.push_back(list);
  }

  for(int i = 0; i<nodes_count; ++i){
    std::getline(in, tmp); 

    std::istringstream string_stream;

    string_stream.str(tmp);

    while (string_stream.good()){
      int j;
      string_stream >> j;
      adjacency_matrix[i][j] = 1;
    }
  };
  graph.adjacency_matrix = adjacency_matrix;
  return graph;
};
