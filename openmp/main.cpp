#define _BSD_SOURCE

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream> 

#include <time.h> 
#include <sys/time.h> 

#include "lib/graph_loader.h"
#include "lib/utils.h"

int main(int argc, char* argv[]) {
  GraphLoader loader(argv[1]);

  Graph graph = loader.load();

  bool is_connected = is_graph_connected(floyd(graph));

  std::cout << "Graph is connected - " << is_connected << '\n';

  return 0;
}