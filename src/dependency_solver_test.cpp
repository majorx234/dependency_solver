#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "dependency_solver.h"



void print_dep_lists(std::vector<std::vector<std::string>> dep_lists)
{
  for(auto& dep_list : dep_lists)
  {
    std::cout << "---------------------" << '\n' << " Element: " << dep_list.front() << " depends on: " << '\n';

    for(auto& element : dep_list )
    {
      if(dep_list.front() != element)
        std::cout << element << '\n';
    }
    std::cout << "---------------------" << '\n';
  }
}
int main(int argc, char const *argv[])
{
  std::vector<std::vector<std::string>> dep_lists;
  std::vector<std::string> first_dep_list;
  std::vector<std::string> second_dep_list;
  std::vector<std::string> third_dep_list;
  std::vector<std::string> fourth_dep_list;
  std::vector<std::string> fifth_dep_list;



  std::string node_1_1, node_1_2, node_1_3, node_2_1, node_2_2, node_2_3, node_2_4, node_3_1, node_4_1, node_5_1, node_5_2, node_5_3, node_5_4 ;
  
  node_1_1 = "UrFisch";
  node_1_2 = "Aal"; 
  node_1_3 = "Hai"; 
  node_2_1 = "UrReptil"; 
  node_2_2 = "T-Rex";
  node_2_3 = "Gecko"; 
  node_2_4 = "Eidechse"; 
  node_3_1 = "Insekt";
  node_4_1 = "Ur_tier";

  node_5_1 = "Quastenflosser";
  node_5_2 = "UrFisch";
  node_5_3 = "UrReptil";
  node_5_4 = "Insekt";

  first_dep_list.push_back(node_1_1);
  first_dep_list.push_back(node_1_2);
  first_dep_list.push_back(node_1_3);
  first_dep_list.push_back(node_2_1);

  second_dep_list.push_back(node_2_1);
  second_dep_list.push_back(node_2_2);
  second_dep_list.push_back(node_2_3);
  second_dep_list.push_back(node_2_4);

  third_dep_list.push_back(node_3_1);
  third_dep_list.push_back(node_1_1);

  fourth_dep_list.push_back(node_4_1);
  fourth_dep_list.push_back(node_1_1);
  fourth_dep_list.push_back(node_3_1);

  fifth_dep_list.push_back(node_5_1);
  fifth_dep_list.push_back(node_5_2);
  fifth_dep_list.push_back(node_5_3);
  fifth_dep_list.push_back(node_5_4);


  dep_lists.push_back(first_dep_list);
  dep_lists.push_back(second_dep_list);
  dep_lists.push_back(third_dep_list);
  dep_lists.push_back(fourth_dep_list);
  dep_lists.push_back(fifth_dep_list);

  print_dep_lists(dep_lists);
  DependencySolver my_dep_solver(dep_lists);
  my_dep_solver.printEdges();

  std::vector<std::string> ordered_list;
  my_dep_solver.getOrderedList(&ordered_list);

  unsigned int i = 0;
  for(auto& item : ordered_list)
  {
    std::cout << " Item " << i << ": " << item << '\n';
    i++;
  }
  return 0;
}