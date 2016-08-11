#include <vector>
#include "graph.h"
#include "component.h"

#ifndef FIND_COMP
#define FIND_COMP

std::vector<Component> find_components(Graph graph);
std::vector<Component> normalize(std::vector<Component> components);

#endif