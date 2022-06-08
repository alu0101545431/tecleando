#include <iostream>

int ChangeHour(int& hour, int& sum) {
  return (hour + sum) % 12;
}

int main() {
  int hour = 0, sum = 0;
  std::cout << "[INPUT] What time is it? > ";
  std::cin >> hour;
  std::cout << "[INPUT]: Quantity of hours > ";
  std::cin >> sum;
  std::cout << "[RESULT]: The new hour is " << ChangeHour(hour, sum) << std::endl;
  return 0;
}
