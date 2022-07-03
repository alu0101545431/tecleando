#include <iostream>
#include <fstream>

#include "delete.h"

int main(int argc, char *argv[]) {
  std::ifstream input_file(argv[1], std::ios_base::in);
  std::ofstream output_file(argv[2], std::ios_base::out);
  DeleteBlankLines(input_file, output_file);
}