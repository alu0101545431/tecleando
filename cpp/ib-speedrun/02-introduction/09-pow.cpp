#include <iostream>
#include <cmath>

void PrintPow(int& number) {
  for (int i = 0; i < number + 1; ++i) {
    std::cout << pow(2, i) << " ";
  }
}

int main() {
  int number = 0;
  std::cout << "[INPUT]: 2^n, enter n > ";
  std::cin >> number;
  PrintPow(number);
  std::cout << std::endl;
  return 0;
}
