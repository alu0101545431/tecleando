#include <iostream>
#include <sstream>
#include <string>

#include "switch_case.h"

int main(int argc, char const *argv[]) {
  std::string text = "";
  std::stringstream input;
  input << argv[1];
  input >> text;

  std::cout << "[INFO]: Original >" << text << std::endl;
  SwitchCase(text);
  std::cout << "[INFO]: Modified >" << text << std::endl;
  return 0;
}
