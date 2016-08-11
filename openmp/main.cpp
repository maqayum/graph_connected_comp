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
#include "lib/find_components.h"
#include "lib/component.h"

int main(int argc, char* argv[]) {
  GraphLoader loader(argv[1]);

  Graph graph = loader.load();

  std::vector<Component> comps;

  struct timeval timeStart, timeEnd;
  

  comps = normalize(find_components(graph));

  std::cout << "Componetns size: " << comps.size() << '\n';

  return 0;
}