#include <iostream>

#include "src/TreeMap.hpp"
 
int main() {
  TreeMap map;
 
  // Insert a number of key-value pairs into the tree map
  map.insert("keyOne", "valueOne");
  map.insert("keyTwo", "valueTwo");
  map.insert("keyThree", "valueThree");
 
  // Prints out valueOne
  std::cout << map.get("keyOne");
 
  // Prints out valueThree
  std::cout << map.get("keyThree");
 
  // Prints out an empty string or some default value of your choice
  std::cout << map.get("keyDoesNotExist");
 
  // Deletes the key-value pair from the tree map
  map.deleteKey("keyOne");
}