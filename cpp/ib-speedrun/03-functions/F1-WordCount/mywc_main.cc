#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "mywc.h"

int main(int argc, const char* argv[]) {
  Usage(argc, argv);
  std::vector<int> word_count;
  std::string string_input_file{""};
  std::stringstream string_stream;
  string_stream << argv[1];
  string_stream >> string_input_file;
  word_count = WordCount(string_input_file);
  std::cout << "a";
  for (size_t i = 0; i < word_count.size(); ++i) {
    std::cout << word_count[i];
    if (i != (word_count.size() - 1)) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
  return 0;
}
