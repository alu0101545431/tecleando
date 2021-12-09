/**
  * @author Adrián Lima García
  * @bug No bugs yet.
  * @see
  */

#include <iostream>

bool IsMultiple (int number_to_check, int candidate_number) {
  if (candidate_number % number_to_check == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int number_to_check = 0, counter_of_multiples = 0, number_candidate = 0;
  std::cin >> number_to_check;
  while (std::cin >> number_candidate) {
    if (IsMultiple(number_to_check, number_candidate)) {
      ++counter_of_multiples;
    }
  }
  std::cout << counter_of_multiples << std::endl;
  return 0;
}
