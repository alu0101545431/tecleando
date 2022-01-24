#include <iostream>
#include <string>

#include "alphabet.h"

// Function to read the values
std::string& AskForString() {
  std::string input_string;
  std::cout << "[INPUT]: Put the string you want to convert:" << std::endl;
  std::cin >> input_string;
  return input_string;
}

// Function to apply the conversion
std::string& ConvertString (std::string& string_to_convert) {
  std::string new_string;
  for (auto letter: string_to_convert) {
    if (std::isalpha(letter)){
      new_string += (letter + 1);
    } else {
      new_string += letter;
    }
    
  }
}