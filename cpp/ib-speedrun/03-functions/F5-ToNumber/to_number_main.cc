#include <iostream>
#include <fstream>

#include "to_number.h"

int main(int argc, char const *argv[]) {
  std::ifstream first_file{argv[1], std::ios_base::in};
  std::ofstream second_file{argv[2], std::ios_base::out};
  
  ToNumber(first_file, second_file);
  return 0;
}
