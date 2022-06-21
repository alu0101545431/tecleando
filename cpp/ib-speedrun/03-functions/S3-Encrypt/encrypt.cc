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

void Encrypt(std::string& text) {
  for (int index = 0; index < text.size(); ++index) {
    if (isalpha(text.at(index))) {
      if (isalpha(text.at(index) + 1)) {
        text.at(index) = text.at(index) + 1;
      } else {
        if (islower(text.at(index))) {
          text.at(index) = 'a';
        } else {
          text.at(index) = 'A';
        }
      }
    }
  }
}