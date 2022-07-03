#include <iostream>
#include <sstream>
#include <string>

#include "find.h"

int main(int argc, char const *argv[]) {
  Usage(argc, argv);
  std::string text = "";
  std::stringstream input, input2;
  char letter;
  input << argv[1];
  input >> text;
  input2 << argv[2];
  input2 >> letter;
  
  
  

  std::cout << "[INFO]: Original >" << text << std::endl;
  
  std::cout << "[INFO]: Found n times >" << Find(text, letter) << std::endl;
  return 0;
}