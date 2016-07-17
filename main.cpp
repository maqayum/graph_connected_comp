#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lib/graph_loader.h"

int main(int argc, char* argv[]) {
  GraphLoader loader("graph.txt");

  Graph graph = loader.load();

  for(int i = 0; i < graph.adjacency_list.size(); ++i){
    for(int j = 0; j< graph.adjacency_list[i].size(); ++j){
      std::cout << graph.adjacency_list[i][j];
    };
    std::cout << '\n';
  };

  return 0;
}