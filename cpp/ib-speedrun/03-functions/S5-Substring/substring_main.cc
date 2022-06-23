#include <iostream>
#include <sstream>
#include <string>

#include "substring.h"

int main(int argc, char const *argv[]) {
  Usage(argc, argv);
  std::string text = "";
  std::stringstream input, input2, input3;
  int start, end;
  input << argv[1];
  input >> text;
  input2 << argv[2];
  input2 >> start;
  input3 << argv[3];
  input3 >> end;
  
  
  

  std::cout << "[INFO]: Original > " << text << std::endl;
  
  std::cout << "[INFO]: Substring > " << Substring(text, start, end) << std::endl;
  return 0;
}