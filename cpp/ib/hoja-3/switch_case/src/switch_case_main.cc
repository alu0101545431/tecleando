#include <iostream>
#include <string>

#include "switch_case.h"

int main(int argc, char const *argv[]) {
  Usage(argc, argv);
  std::string phrase = argv[1];
  SwitchCase(phrase);
  std::cout << phrase << std::endl;
  return 0;
}
