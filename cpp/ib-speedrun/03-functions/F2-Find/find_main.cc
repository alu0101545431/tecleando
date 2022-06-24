#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>

#include "find.h"


int main(int argc, char* argv[]) {
  std::string first_file_str = "", second_file_str = "";
  first_file_str = argv[1]; //Te amo miaumor
  second_file_str = argv[2]; // Te_amo++;
  std::ifstream first_file{first_file_str}, second_file{second_file_str};
  std::cout << "[INFO]: File is not the same at line " << Find(first_file, second_file);
  return 0;
}