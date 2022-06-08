// g++ -std=c++14 -g -Wall -o 01-pair 01-pair.cpp
#include <iostream>

int main() {
  int input = 0;
  std::cout << "[INPUT]: Enter a number > ";
  std::cin >> input;
  if (input % 2) {
    std::cout << "[INFO]: It is not pair." << std::endl;
  } else {
    std:: cout << "[INFO]: It is pair." << std::endl;
  }
  return 0;
}
