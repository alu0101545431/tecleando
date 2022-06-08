// g++ -std=c++14 -g -Wall -o 02-radius 02-radius.cpp
#include <cmath>
#include <iostream>

double Perimeter(double& radius) { return 2 * M_PI * radius; }
double Area(double& radius) {return M_PI * pow(radius, 2); }

int main() {
  double radius = 0;
  std::cout << "[INPUT]: Enter the radius" << std::endl;
  std::cin >> radius;
  std::cout << "[INFO]: Perimeter: " << Perimeter(radius) << std::endl;
  std::cout << "[INFO]: Area: " << Area(radius) << std::endl;
  return 0;
}
