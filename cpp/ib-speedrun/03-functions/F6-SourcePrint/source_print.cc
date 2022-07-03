#include <iostream>
#include <string>
#include <fstream>

#include "source_print.h"

void PrintSource(std::ifstream& input, std::ofstream& output) {
  std::string line = "";
  while (getline(input, line)) {
    output << line << std::endl;
  }
}