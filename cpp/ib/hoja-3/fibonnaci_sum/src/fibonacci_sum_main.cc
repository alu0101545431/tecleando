#include <iostream>
#include <string>

#include "fibonacci_sum.h"

int main(int argc, char const *argv[]) {
  int input_number = 0;
  Usage(argc, argv);
  input_number = std::stoi(argv[1]);
  std::cout << FibonacciSum(input_number) << std::endl;
  return 0;
}
