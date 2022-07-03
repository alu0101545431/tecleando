#include "find.h"

#include <iostream>
#include <sstream>
#include <string>

const std::string KHelpMessage =
    "Sample text \n Usage: "
    "./program <string>";

void Usage(int argc, const char* argv[]) {
  if (argc != 3) {
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

int Find(std::string& text, char& letter) {
  int counter  = 0;
  for (int index = 0; index < text.size(); ++index) {
    if (text.at(index) == letter) counter++;
  }
  if (counter == 0) return -1;
  return counter;
}