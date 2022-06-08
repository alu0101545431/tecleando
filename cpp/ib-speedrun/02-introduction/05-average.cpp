#include <iostream>

#define NUMBER_OF_ELEMENTS 4

double Average() {
  int first = 0, second = 0, third = 0, fourth = 0;
  std::cin >> first >> second >> third >> fourth;
  std::cout << "[RESULT]: ";
  return double(first + second + third + fourth) / int(NUMBER_OF_ELEMENTS);
}

int main() {
  std::cout << "[INPUT]: Join the four values next > " << Average()
            << std::endl;
  return 0;
}
