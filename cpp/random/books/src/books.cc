#include "books.h"

#include <iostream>
#include <string>

void PrintHelpMessage() {
  std::cout << "[HELP]: The objective of this program is to apply the given "
            << "taxes to a certain amount of books" << std::endl
            << "The syntax to use this program this program "
            << "properly is the following:" << std::endl
            << "[SYNTAX]: "
            << "./books TAX" << std::endl
            << "[ADVICE]: Please, note that you need to use an integer number"
            << "to set tax you are going to use. For example, 7 will mean a"
            << " 7 percent tax" << std::endl;
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

double Book::PriceWithTaxes(int& taxes_to_apply) {
  double final_price;
  // We'll multiply the taxes per 1.0 to convert from int to double.
  final_price = (((taxes_to_apply * 1.0) / 100) + 1.0) * price_;
  return final_price;
}