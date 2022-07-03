#include <fstream>
#include <iostream>
#include <string>

/*
 * @brief Check whether two files are equal or not
 * @param input_file: to get the data
 * @param output_file: file to write the changes
 * @return void
 */
void DeleteBlankLines(std::ifstream& input_file, std::ofstream& output_file) {
  std::string line = "";
  while (getline(input_file, line)) {
    output_file << line;
  }
}