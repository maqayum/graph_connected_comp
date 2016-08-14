#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream> 
#include <algorithm>

#include "graph.h"

std::vector< std::vector<int> > floyd(Graph graph){
  std::vector< std::vector<int> > matrix = graph.adjacency_matrix;
  #pragma omp parallel for schedule(static)
  for(int k=0; k<graph.nodes_count; ++k){
    for(int i=0; i<graph.nodes_count; ++i){
      for(int j=0; j<graph.nodes_count; ++j){
        #pragma omp critical 
        {
          matrix[i][j] = std::min(matrix[i][j], (matrix[i][k] + matrix[k][j]));
        }
      }
    }
  }
  return matrix;
};

bool is_graph_connected(std::vector< std::vector<int> > matrix){
  bool result = true;
  for(int i=0; i<matrix.size(); ++i){
    for(int j=0; j<matrix.size(); ++j){
      if (matrix[i][j] > matrix.size()){
        result = false;
      }
    }
  }   
  return result;
};

void print_matrix(std::vector< std::vector<int> > matrix){
  std::cout << "Print matrix - " << matrix.size() << '\n';
  #pragma omp parallel for schedule(static)
  for(int i=0; i<matrix.size(); ++i){
    for(int j=0; j<matrix.size(); ++j){
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  };
}