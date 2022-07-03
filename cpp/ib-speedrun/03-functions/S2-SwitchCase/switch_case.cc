#include "encrypt.h"

#include <iostream>
#include <sstream>
#include <string>

const std::string KHelpMessage =
    "Sample text \n Usage: "
    "./program <string>";

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

void SwitchCase(std::string& phrase) {
  for (int index = 0; index < phrase.size(); ++index) {
    if (isalpha(phrase.at(index))) {
      if (islower(phrase.at(index))) {
        phrase.at(index) = std::toupper(phrase.at(index));
      } else {
        phrase.at(index) = std::tolower(phrase.at(index));
      }
    }
  }
}