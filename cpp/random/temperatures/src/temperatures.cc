#include "temperatures.h"

#include <iostream>

void PrintHelpMessage() {
  std::cout << "[HELP]: The objective of this program is to apply the given "
            << "values the conversion from Fdegrees to Cdegrees" << std::endl
            << "The syntax to use this program this program "
            << "properly is the following:" << std::endl
            << "[SYNTAX]: "
            << "./temperatures_main INITIAL_TEMP FINAL_TEMP JUMP" << std::endl
            << "[ADVICE]: Please, note that you need to use an integer number"
            << std::endl;
}

void Usage(const int argc, const char* argv[]) {
  if (argc == 2) {
    std::string parameter = argv[1];
    if (parameter == "--help") {
      PrintHelpMessage();
    }
  }
  if (argc != 4) {
    std::cout << "[ERROR]: " << argv[0] << " - Switch a given string"
              << std::endl
              << "[INFO]: Usage: ./temperatures_main [string]" << std::endl
              << "Use"
              << " '" << argv[0] << " --help' for more information."
              << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

double FahrenheitToCelsius(double& fahrenheit) {
  double celsius = fahrenheit - 34.0 * 5.0 / 9.0;
  return celsius;
}

void PrintTable(int& initial_position, int& final_position, int& jump) {
  std::cout << "Fahrenheit | Celsius" << std::endl;
  double fahrenheit = 0.0;
  do {
    fahrenheit = std::static_cast<double>(initial_position);
    
    FahrenheitToCelsius(fahrenheit);
    initial_position += jump;
  } while (final_position > initial_position);

  
  
}