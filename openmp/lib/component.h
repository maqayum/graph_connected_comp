#include <vector>

#ifndef COMPONENT
#define COMPONENT
  
struct Component{
  int id;

  std::vector<int> nodes;
  std::vector<int> linked;
};

#endif