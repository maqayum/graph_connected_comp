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

int main(int argc, char* argv[]) {
  GraphLoader loader(argv[1]);

  Graph graph = loader.load();

  std::vector< std::vector<int> > comps;

  struct timeval timeStart, timeEnd;

  gettimeofday(&timeStart, NULL);

  comps = find_components(graph);

  gettimeofday(&timeEnd, NULL);

  std::cout << "This effing slow piece of code took "
          << ((double)((timeEnd.tv_sec - timeStart.tv_sec) * 1000000 + timeEnd.tv_usec - timeStart.tv_usec) / (double)1000000)
          << " us to execute."
          << std::endl;

  // std::cout << "Componetns size \n";
  // std::cout << comps.size() << '\n';
  // for(int i=0; i < comps.size(); i++){
  //   std::cout << comps[i].size() << '\n';
  // };

  return 0;
}