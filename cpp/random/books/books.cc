#include "books.h"

#include <iostream>
#include <string>

void PrintHelpMessage() {
  std::cout << "[HELP]: The objective of this program is to switch "
            << "between lowercases and uppercases of a given string."
            << std::endl
            << "The syntax to use this program this program "
            << "properly is the following:" << std::endl
            << "[SYNTAX]: "
            << "./switch_case STRING" << std::endl
            << "[ADVICE]: Please, note "
            << "that if you are going to use a string with more than one word,"
            << "you will need to put it between quotting marks.";
}

void Usage(const int argc, const char* argv[]) {
  if (argc == 2) {
    std::string parameter = argv[1];
    if (parameter == "--help") {
      PrintHelpMessage();
    }
  }
  if (argc != 2) {
    std::cout << "[ERROR]: " << argv[0] << " - Switch a given string"
              << std::endl
              << "[INFO]: Usage: ./switch_case [string]" << std::endl
              << "Use"
              << " '" << argv[0] << " --help' for more information."
              << std::endl;
    std::exit(EXIT_FAILURE);
  }
}