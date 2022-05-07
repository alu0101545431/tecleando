#include "iostream"
#include "string"

void PrintHelpMessage() {
  std::cout
      << "[INFO]: ./fibonacci_sum [n] where 'n' is the number to calculate"
      << std::endl;
}

void Usage(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << argv[0] << " forgot number like argument" << std::endl
              << "Try '" << argv[0] << " --help' for more information"
              << std::endl;
    std::exit(0);
  }
  if (argc == 2) {
    std::string parameter = argv[1];
    if (parameter == "--help") {
      PrintHelpMessage();
    }
  }
}

int FibonacciSum(int input_number) {
  if (input_number == 1) {
    
  }
}