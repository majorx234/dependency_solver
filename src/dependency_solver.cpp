#include <iostream> // std::cout
#include <utility> // std::pair
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>

#include "dependency_solver.h"

using namespace boost;


DependencySolver::DependencySolver(std::vector<std::vector<std::string>> dependency_lists)
{
  unsigned int nelements = 0;
  for(auto dep_list : dependency_lists) {
    auto ref_dependency = dep_list.front();
    elements.push_back(ref_dependency);
    nelements++;
    unsigned int ref_dependency_id = nelements;
    for(auto& i : dep_list) {
      if(i != ref_dependency)
      {
        elements.push_back(i);
        nelements++;
        Edge dep( ref_dependency_id-1, nelements-1);
        neededBy.push_back(dep);
      }
    }
  }
  // std::size_t nedges = neededBy.size();
  Graph dependency_graph(neededBy.begin() ,neededBy.end() ,nelements);
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

std::vector<std::string> getOrderedList()
{
  typedef std::list<Vertex> MakeOrder;
  MakeOrder::iterator i;
  MakeOrder make_order;

  topological_sort(g, std::front_inserter(make_order));
  
}