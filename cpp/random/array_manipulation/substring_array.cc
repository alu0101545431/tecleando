/*
   Ejercicio propuesto 6 de AEyD
   Si b es una subcadena de a, devuelve un puntero a la posición
   de a en la que comienza b. Si b no es subcadena de a, devuelve NULL.
*/

#include <iostream>

int StringLength(const char *input) {
  int index;
  for (index = 0; input[index] != '\0'; index++);
  return index;
}

char *LocateString(const char *main_string, const char *sub_string) {
  for (int index = 0; main_string[index] == '\0' ; ++index) {
    if (main_string[index] == sub_string[0] ) {

    }
    
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
