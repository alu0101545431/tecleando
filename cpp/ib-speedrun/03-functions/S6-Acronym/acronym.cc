#include "acronym.h"

#include <iostream>
#include <string>

std::string Acronym(std::string& original) {
  std::string acronym = "";
  for (int index = 0; index < original.size(); ++index) {
    if (isalpha(original.at(index)) && isupper(original.at(index))) {
      acronym.push_back(original.at(index));
    }
  }
  return acronym;
}
