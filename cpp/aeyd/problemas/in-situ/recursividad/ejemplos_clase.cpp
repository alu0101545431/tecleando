#include "iostream"
#include "vector"
#include "string"

int Potencia(int base, int exponente) {
   return (exponente ? base * Potencia(base, exponente - 1) : 1);
}

bool IsPal(std::vector<char>& str, int left, int right) {
  if (left >= right) return str[left] == str[right];
  return IsPal(str, left + 1, right - 1) && str[left] == str[right];
}

int main(int argc, char const *argv[])
{
  int base;
  int exponente;
  std::cout << "[INPUT]: Introduzca una potencia: ";
  std::cin >> base;
  std::cin >> exponente;
  std::cout << "[RESULTADO]: " << Potencia(base, exponente) << std::endl;
  std::vector<char> cadena = {'a', 'm', 'o', 'r', 'a', 'r', 'o','m', 'a'};
  std::vector<char> cadena2 = {'x', 'd', 'd'};
  std::cout << IsPal(cadena, 0, cadena.size() - 1) ? "YES\n" : "NO\n";
  std::cout << IsPal(cadena2, 0, cadena2.size() - 1) ? "YES\n" : "NO\n";
  return 0;
}
