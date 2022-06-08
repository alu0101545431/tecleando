#include <iostream>

void RevertDigits(int& number) {
  while (number != 0) {
    std::cout << number % 10;  // We print the last digit
    number /= 10;  // We pass to the next digit by storing the int part
  }
  std::cout << std::endl;  // clean screen
}

int main() {
  int input = 0;
  std::cout << "[INPUT]: Enter a number > ";
  std::cin >> input;
  std::cout << "[RESULT]:" << std::endl;
  RevertDigits(input);
  return 0;
}
