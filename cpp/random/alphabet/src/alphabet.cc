#include "alphabet.h"

#include <iostream>
#include <string>

// Function to read the values
std::string& AskForString() {
  std::string input_string;
  std::cout << "[INPUT]: Put the string you want to convert:" << std::endl;
  std::getline(std::cin, input_string);
  return input_string;
}

// Function to apply the conversion
std::string& ConvertString(std::string& string_to_convert) {
  std::string new_string;
  for (char letter : string_to_convert) {
    // We check whether it is alphanumeric or not
    if (std::isalpha(letter)) {
      letter += (letter + 1);
      // Substract 26 in the case it is not alphanumeric after the conversion
      if (!(isalpha(letter + 1))) {
        letter -= 26;
      }
      new_string += letter;
    } else {
      new_string += letter;
    }
  }
  return new_string;
}