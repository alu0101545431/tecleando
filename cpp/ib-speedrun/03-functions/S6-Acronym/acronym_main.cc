#include <iostream>
#include <string>

#include "acronym.h"

int main() {
  std::string original_string = "Fernando Alonso";
  std::cout << "[INFO]: Enter the string > ";
  std::getline(std::cin, original_string);
  std::cout << "[INFO]: Acronym > " << Acronym(original_string) << std::endl;

  return 0;
}
