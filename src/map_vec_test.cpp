#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "map_vec.h"

int main(int argc, char const *argv[])
{
  MapVec map_vec_tester;

  int i_1_1, i_1_2, i_1_3;

  i_1_1 = 0; 
  i_1_2 = 0; 
  i_1_3 = 0;

  std::string node_1_1, node_1_2, node_1_3;

  node_1_1 = "UrFisch";
  node_1_2 = "Aal"; 
  node_1_3 = "Hai"; 

  i_1_1 = map_vec_tester.push_back(node_1_1);
  i_1_2 = map_vec_tester.push_back(node_1_2);
  i_1_3 = map_vec_tester.push_back(node_1_3);
  

  std::cout << "First test: Access "  << '\n';
  std::cout << "---------------------------------------" << '\n';
  std::cout << "Element No: " << i_1_1 << " is string: " << map_vec_tester[i_1_1] << " with id: " << map_vec_tester[node_1_1] << " should be: " << node_1_1 << '\n';
  std::cout << "Element No: " << i_1_2 << " is string: " << map_vec_tester[i_1_2] << " with id: " << map_vec_tester[node_1_2] << " should be: " << node_1_2 << '\n';
  std::cout << "Element No: " << i_1_3 << " is string: " << map_vec_tester[i_1_3] << " with id: " << map_vec_tester[node_1_3] << " should be: " << node_1_3 << '\n';

  std::cout << "Second test: Loops" << '\n';
  std::cout << "---------------------------------------" << '\n';

  for (auto it : map_vec_tester)
    std::cout << "Element is: " << it << '\n';

  std::cout << "Second test: Find" << '\n';
  std::cout << "---------------------------------------" << '\n';
  auto  element_no = map_vec_tester.find("Aal");
  if (element_no != map_vec_tester.map_end());
    std::cout << "Element is: " << element_no->second << '\n';
  return 0;
}
