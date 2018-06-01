#ifndef MAP_VEC_H
#define MAP_VEC_H

#include <map>
#include <vector>
#include <memory>

class MapVec
{

  std::map<std::string,int> string2int;
   
  using map_vec_t = std::vector<std::string>;
  map_vec_t int2string;
public:
  typedef std::allocator<MapVec> allocator_type;
  typedef std::allocator<MapVec>::value_type value_type; 
  typedef std::allocator<MapVec>::reference reference;
  typedef std::allocator<MapVec>::const_reference const_reference;
  typedef std::allocator<MapVec>::difference_type difference_type;
  typedef std::allocator<MapVec>::size_type size_type;
  typedef std::allocator<MapVec>::pointer pointer;

  using iterator = map_vec_t::iterator;
  using const_iterator = map_vec_t::const_iterator;

  int &operator[](const std::string& index){
    
    // check if key already exists
    std::map<std::string ,int>::iterator finder = string2int.find(index);
    if(finder != string2int.end())
    {
      return string2int[index];
    }
    else
    {
      return push_back(index);       
    }
  };
  std::string &operator[](const int& index){
    return int2string[index]; 
  };
  std::map<std::string, int>::iterator find(const std::string& key){
    return string2int.find(key); 
  };  
  int &at(const std::string& k){
    return string2int.at(k);
  };
  int &push_back(std::string index){
    int2string.push_back(index);
    int int_index = static_cast<int>(int2string.size() - 1 );
    string2int.insert ( std::pair<std::string,int>(index, int_index));
    return string2int[index];
  };

  MapVec(){};
  MapVec(const MapVec&) = default;
  ~MapVec(){};

  MapVec& operator=(const MapVec& other){
    string2int = other.string2int;
    int2string = other.int2string;
    return *this;
  };

  iterator begin() { return int2string.begin(); }
  iterator end() { return int2string.end(); }
  const_iterator begin() const { return int2string.begin(); }
  const_iterator end() const { return int2string.end(); }
  const_iterator cbegin() const { return int2string.cbegin(); }
  const_iterator cend() const { return int2string.cend(); }

  std::map<std::string, int>::iterator map_begin(){ return string2int.begin(); }
  std::map<std::string, int>::iterator map_end(){ return string2int.end(); }

  void swap(MapVec&);
  size_type size() const{
    return int2string.size();
    };
  size_type max_size() const;
  bool empty() const{return int2string.empty();} ;
};


#endif // MAP_VEC_H
