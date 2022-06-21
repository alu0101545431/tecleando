

#include "count_vowels.h"

#include <iostream>
#include <sstream>
#include <string>

const std::string KHelpMessage =
    "This program count the vowels to a string passed by argument. \n Usage: "
    "./programa <string>";

void Usage(int argc, const char* argv[]) {
  if (argc != 2) {
    std::cout << argv[0] << ": miss string like argument" << std::endl
              << "Try '" << argv[0] << " --help' for more information"
              << std::endl;
    std::exit(0);
  }
  std::string argument1{""};
  std::stringstream string_stream;
  string_stream << argv[1];
  string_stream >> argument1;
  if ((argc == 2) && (argument1 == "--help")) {
    std::cout << KHelpMessage << std::endl;
    std::exit(0);
  }
}

int CountVowels(const std::string& text) {
  int counter = 0;
  for (int index = 0; index < text.size(); ++index) {
    if (std::tolower(text.at(index)) == 'a' ||
        std::tolower(text.at(index)) == 'e' ||
        std::tolower(text.at(index)) == 'i' ||
        std::tolower(text.at(index)) == 'o' ||
        std::tolower(text.at(index)) == 'u') {
      counter++;
    }
  }
  return counter;
}
