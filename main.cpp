#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream> 

#include "lib/graph_loader.h"
#include "lib/find_components.h"

int main(int argc, char* argv[]) {
  GraphLoader loader(argv[1]);

  Graph graph = loader.load();

  std::vector< std::vector<int> > comps;
  comps = find_components(graph);

  #pragma omp parallel
  printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());

  #pragma omp parallel for
  for(int i=0; i<10; ++i){
    std::cout << i << '\n';
  };

  std::cout << "Componetns size \n";
  std::cout << comps.size() << '\n';
  for(int i=0; i < comps.size(); i++){
    std::cout << comps[i].size() << '\n';
  };

  return 0;
}