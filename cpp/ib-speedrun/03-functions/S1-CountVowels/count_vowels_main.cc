#include <iostream>
#include <string>
#include <sstream>
#include "count_vowels.h"

int main(int argc, char const *argv[]) {
  Usage(argc, argv);
  std::string text{""};
  std::stringstream string_stream;
  string_stream << argv[1];
  string_stream >> text;
  std::cout << "Quantity of vowels of word " << text << " = "
            << CountVowels(text) << std::endl;
  return 0;
}
