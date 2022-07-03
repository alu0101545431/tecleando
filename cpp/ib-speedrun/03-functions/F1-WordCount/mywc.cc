#include "mywc.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string KHelpMessage =
    " This program receive one input file like argument and print the "
    "queantity of words, lines and character present in the file\n Usage: "
    "./my_wc <path_file>\n";

void Usage(int argc, const char* argv[]) {
  if (argc == 2) {
    std::string argument1{""};
    std::stringstream string_stream;
    string_stream << argv[1];
    string_stream >> argument1;
    if (argument1 == "--help") {
      std::cout << KHelpMessage;
      std::exit(0);
    }
  }
  if (argc != 2) {
    std::cout << argv[0] << " missing input file arguments. " << std::endl
              << "Try '" << argv[0] << " --help' for more information"
              << std::endl;
    std::exit(0);
  }
}

std::vector<int>& WordCount(const std::string& path_input_file) {
  std::vector<int> result;
  std::ifstream file{path_input_file};
  std::string line = "";
  std::string word = "";
  int line_counter = 0, word_counter = 0, char_counter = 0;
  // We pass line by line while it does not reach the last one
  while (std::getline(file, line)) {
    std::stringstream line_stream;
    line_stream << line;
    while (line_stream >> word) {
      for (int index = 0; index < word.length(); ++index) {
        ++char_counter;
      }
      ++word_counter;
    }
    ++line_counter;
  }
  result.push_back(line_counter);
  result.push_back(word_counter);
  result.push_back(char_counter);
  return result;
}