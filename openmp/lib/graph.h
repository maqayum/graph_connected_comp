#include <vector>

#ifndef GRAPH
#define GRAPH

struct Graph{
  int nodes_count;

  std::vector< std::vector<int> > adjacency_matrix;
};

#endif