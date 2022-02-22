/* ADRIÁN LIMA GARCÍA
   AEyD Tema 1 Problema 4
   Devuelve un valor positivo si b precede alfabéticamente a
   a, negativo si a precede a b y 0 si ambas son iguales.    */

#include <iostream>

int strcmp(const char *a, const char *b) {
  int index = 0;  // we'll use this as an index for the pointer arithmethics
  while ((a[index] != '\0') && (b[index] != '\0')) {
    if (a[index] > b[index]) {
      return 1;
    }
    if (a[index] < b[index]) {
      return -1;
    }
    ++index;
  }
  return 0;  // the other options were rejected, go little rockstar
}

int main() {
  std::cout << "[RESULT]: " << strcmp("rho", "delta") << std::endl;
  std::cout << "[RESULT]: " << strcmp("beta", "beta") << std::endl;
  std::cout << "[RESULT]: " << strcmp("alfa", "algo") << std::endl;
  std::cout << "[RESULT]: " << strcmp("adrian", "adriansito") << std::endl;
  std::cout << "[RESULT]: " << strcmp("adriansito", "adrian") << std::endl;
  return 0;
}
