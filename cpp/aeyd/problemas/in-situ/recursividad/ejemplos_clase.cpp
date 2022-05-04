#include "iostream"

int Potencia(int base, int exponente) {
   return (exponente ? base * Potencia(base, exponente - 1) : 1);
}

int main(int argc, char const *argv[])
{
  int base;
  int exponente;
  std::cout << "[INPUT]: Introduzca una potencia: ";
  std::cin >> base;
  std::cin >> exponente;
  std::cout << "[RESULTADO]: " << Potencia(base, exponente) << std::endl;
  return 0;
}
