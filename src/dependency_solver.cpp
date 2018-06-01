#include <iostream> // std::cout
#include <utility> // std::pair
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>

#include "dependency_solver.h"

using namespace boost;


DependencySolver::DependencySolver(std::vector<std::vector<std::string>> dep_lists)
{
  unsigned int nelements = 0;
  for(auto dep_list : dep_lists) {
    auto ref_dependency = dep_list.front();
    int key_element = 0;
    if(elements.find(ref_dependency) == elements.map_end())
    { // grap
      key_element = elements.push_back(ref_dependency);
      nelements++;         
    }
    else
    {
      key_element = elements[ref_dependency];
    }
    for(auto& i : dep_list) {
      int key_dependency = 0;
      if(i.compare(ref_dependency) != 0 )
      {
        if(elements.find(i) == elements.map_end())
        {  //grap too
          key_dependency = elements.push_back(i);
          nelements++;
        }
        else
        {
          key_dependency = elements[i];
        }   
        Edge dep( key_dependency, key_element);
        neededBy.push_back(dep);
      }
    }
  }
  // maybe need in the future
  // std::size_t nedges = neededBy.size();
  dependency_graph = std::make_shared<Graph>(Graph(neededBy.begin() ,neededBy.end() ,nelements));
}

DependencySolver::~DependencySolver()
{

}

void DependencySolver::printEdges()
{
  for(auto& edge : neededBy)
  {
    std::cout << "Node: " << elements[edge.first] << " depends on " << elements[edge.second] << '\n';
  }
}

int DependencySolver::getOrderedList(std::vector<std::string> *ordered_list)
{
  typedef std::list<Vertex> MakeOrder;
  MakeOrder make_order;

  topological_sort((*dependency_graph), std::front_inserter(make_order));
  for (auto& index : make_order)
  {
      ordered_list->push_back(elements[index]);
  }
  return 0;
}