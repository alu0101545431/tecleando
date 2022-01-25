#include <iostream>

#include "alphabet.h"

// No need to make Usage() function in this case.
int main(int argc, char const *argv[]) {
  std::string string_to_use = AskForString();
  std::cout << "a";
  std::cout << ConvertString(string_to_use) << std::endl;

  return 0;
}
