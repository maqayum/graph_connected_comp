#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream> 
#include <algorithm>
#include "component.h"
#include "graph.h"

Component bypass_to_deep(Graph graph, int node, int used_nodes[], Component &component){
  component.nodes.push_back(node); 
  if(used_nodes[node] == -1){
    #pragma omp critical     
    {
      used_nodes[node] = component.id;
    }      

    for(int i=0; i<graph.adjacency_list[node].size(); ++i){
      int to = graph.adjacency_list[node][i];
      if (used_nodes[to] == -1){
        bypass_to_deep(graph, to, used_nodes, component);
      }
    }
  }
  else{
    if(used_nodes[node] != component.id){  
      component.linked.push_back(used_nodes[node]);
    } 
    else{
    }
  }     
  return component;
}

std::vector<Component> normalize(std::vector<Component> components) { 
  std::vector<int> removed_comp_ids;
  std::vector<Component> normalized; 
  for(int i=0; i<components.size(); ++i){
    if(components[i].linked.size() > 0){
      bool not_all_linked_removed = false;
      for(int j=0; (j<components[i].linked.size()); ++j){
        not_all_linked_removed = not_all_linked_removed || std::find(removed_comp_ids.begin(), removed_comp_ids.end(), components[i].linked[j]) != removed_comp_ids.end();
      }

      if(not_all_linked_removed){
        #pragma omp critical 
        {   
          removed_comp_ids.push_back(components[i].id);
        }
      } else{
        normalized.push_back(components[i]);
      }
    }
    else {
      #pragma omp critical 
      {        
        normalized.push_back(components[i]);
      }
    }
  };
  return normalized;
}

std::vector<Component> find_components(Graph graph){
  std::vector<Component> components;
  int used_nodes[graph.nodes_count];

  #pragma omp parallel for schedule(static)
  for(int i=0; i<graph.nodes_count; ++i){
    used_nodes[i] = -1;
  };


  #pragma omp parallel for
  for (int i=0; i<graph.nodes_count; ++i){
    if (used_nodes[i] == -1) {
      Component component;
      component.id = i;
      bypass_to_deep(graph, i, used_nodes, component);
      #pragma omp critical 
      {
        components.push_back(component);
      }       
    }
  }
  return components;
}