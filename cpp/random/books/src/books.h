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
  // Constructor by default
  Book() {
    name_ = "NULL";
    year_ = 0;
    price_ = 0;
  }
  // Constructor with parameters
  Book(const std::string& input_name, const int& input_year,const double& input_price) {
    name_ = input_name;
    year_ = input_year;
    price_ = input_price;
  }
  // Getters
  std::string GetName() const {
    return name_;
  }
  int GetYear() const {
    return year_;
  }
  double GetPrice() const {
    return price_;
  }
  // Methods of the class
  double PriceWithTaxes (int& taxes_to_apply);
};
