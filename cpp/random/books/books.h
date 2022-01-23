#include <iostream>
#include <string>

void Usage(int argc, const char *argv[]);
void PrintHelpMessage();

class Book {
 private:
  std::string name_;
  int year_;
  double price_;
 public:
  Book() {
    name_ = "NULL";
    year_ = 0;
    price_ = 0;
  }
  Book(std::string& input_name, int& input_year, double& input_price) {
    name_ = input_name;
    year_ = input_year;
    price_ = input_price;
  }
};
