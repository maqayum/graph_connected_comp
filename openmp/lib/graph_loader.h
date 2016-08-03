#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "graph.h"

#ifndef GRAPH_LOADER
#define GRAPH_LOADER

class GraphLoader{
private: 
  std::string file_path;

public: 
  GraphLoader(std::string file_path); 

  Graph load();
};


#endif