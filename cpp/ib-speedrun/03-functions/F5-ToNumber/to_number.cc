#include "to_number.h"

#include <fstream>
#include <iostream>
#include <string>

void ToNumber(std::ifstream& input_file, std::ofstream& output_file) {
  int line_counter = 0;
  std::string line = "";
  while (getline(input_file, line)) {
    output_file << ++line_counter << ": " << line << std::endl;
  }
}