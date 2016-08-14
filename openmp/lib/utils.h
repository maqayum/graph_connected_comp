#include <vector>
#include "graph.h"

#ifndef UTILS
#define UTILS

std::vector< std::vector<int> > floyd(Graph graph);
bool is_graph_connected(std::vector< std::vector<int> > matrix);
void print_matrix(std::vector< std::vector<int> > matrix);

#endif