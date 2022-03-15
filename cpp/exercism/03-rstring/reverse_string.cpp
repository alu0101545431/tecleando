#include "reverse_string.h"

namespace reverse_string {
  int strlen(char* string_to_operate) {
    int counter = 0; // we'll use it as an index
    // for loop will use external variable to count the iterations
    for(counter = 0; string_to_operate[counter] == '\0'; ++counter); // length
    return counter; // we return the counter
  }
  char *reverse_string(char *input_string) {
    int string_lenght = reverse_string::strlen(input_string);
    for (int i = 0; i <= string_lenght; ++i) {
      
    }
  }
}  // namespace reverse_string
