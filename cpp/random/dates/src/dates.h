#include <iostream>

void Usage(int argc, char *argv[]);
void UsageMessage();

class Date {
 private:
  int day_;
  int month_;
  int year_;
 public:
  Date() {
    day_ = 0;
    month_ = 0;
    year_ = 0;
  };
  Date(int&, int&, int&);
  ~Date();
};

Date::Date(/* args */) {}

