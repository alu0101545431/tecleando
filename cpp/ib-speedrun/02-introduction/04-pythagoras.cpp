#include <cmath>
#include <iostream>

double RectangleTriangleHypotenuse(double& first_leg, double& second_leg) {
  return sqrt(pow(first_leg, 2) + pow(second_leg, 2));
}

int main() {
  double first_leg = 0, second_leg = 0;
  std::cout << "[INFO]: First leg (cms) > ";
  std::cin >> first_leg;
  std::cout << "[INFO]: Second leg (cms) > ";
  std::cin >> second_leg;
  std::cout << "[RESULT]: Hypotenuse is "
            << RectangleTriangleHypotenuse(first_leg, second_leg) << std::endl;
  return 0;
}
