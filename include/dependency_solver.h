#ifndef DEPENDENCY_SOLVER_H
#define DEPENDENCY_SOLVER_H

#include <utility>
#include <string>
#include <vector>
#include <memory>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>

typedef std::pair<int, int> Edge;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS, boost::property<boost::vertex_color_t, boost::default_color_type>> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

class DependencySolver{
public:
  DependencySolver(std::vector<std::vector<std::string>> dependency_lists);
  ~DependencySolver();
  void printEdges();
private:
  std::vector<std::string> elements;
  std::vector<Edge> neededBy;
  std::shared_ptr<Graph> dependency_graph;
};

#endif // DEPENDENCY_SOLVER_H
