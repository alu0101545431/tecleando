#include <iostream>

char *strcopy(char *output, char *input) {
  int lenght = 0;
  for (lenght = 0; input[lenght] != '\0'; ++lenght);
  for (int index = 0; index <= lenght; ++index) {
    output[index] = input[index];
  }
  return output;
}

int main() {
  char x[10];
  strcopy(x, "algoritmo");
  std::cout << x << std::endl;
  return 0;
}
