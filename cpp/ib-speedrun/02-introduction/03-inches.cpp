#include <iostream>

#define INCHES 2.54

double CentimetersToInches(double& cms) { return cms / double(INCHES); }

int main() {
  double centimeters = 0;
  std::cout << "[INPUT]: Enter the cms > ";
  std::cin >> centimeters;
  std::cout << "[CONVERSION]: " << CentimetersToInches(centimeters)
            << std::endl;
  return 0;
}
