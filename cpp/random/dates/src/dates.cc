#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "dates.h"

void Usage(int argc, char *argv[]) {
    if (argc == 2) {
      std::string argument = argv[1];
      if (argument == "--help") {
        UsageMessage();
        std::exit(EXIT_FAILURE);
      }
    }
    if (argc != 4) {
      std::cout << argv[0] << " - Manage and Represent Dates" << std::endl
                << "[INFO]: Usage: ./dates dd/mm/aa N output_file.txt"
                << std::endl
                << "Use"
                << " '" << argv[0] << " --help' for more information."
                << std::endl;
      std::exit(EXIT_FAILURE);
    }
  }