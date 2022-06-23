#include "substring.h""

#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>

const std::string KHelpMessage =
    "Sample text \n Usage: "
    "./program <string>";

void Usage(int argc, const char* argv[]) {
  if (argc != 4) {
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

std::string Substring(std::string& original, int& start, int& end) {
  assert(start >= 0 && end < original.size());
  std::string modified = "";
  for (int index = start; index <= end; ++index) {
    modified.push_back(original.at(index));
  }
  return modified;
}