#include <fstream>
#include <iostream>
#include <string>
#include "source_print.h"

int main(int argc, char const *argv[]) {
  std::ifstream input{"source_print_main.cc", std::ios_base::in};
  std::ofstream output{argv[1], std::ios_base::out};
  PrintSource(input, output);
  
  return 0;
}
