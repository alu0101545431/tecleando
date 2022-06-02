#include <iostream>
#include "vector_t.h"

int NumberOfDigits(unsigned int number) {
  if (number) {
    return 1 + NumberOfDigits(number / 10);
  }
  return 0;
}

int SumOfDigits(unsigned int number) {
  if (number) {
    return number % 10 + SumOfDigits(number / 10);
  }
  return 0;
}

int BinaryConversion(unsigned int number) {
  if (number <= 1) {
    return number;
  }
  return BinaryConversion(number / 2) * 10 + number % 2;  // el x10 desplaza
}

int Collatz(unsigned int number) {
  if (number == 1) return 1;
  if (!(number % 2)) return 1 + Collatz(number / 2);
  return 1 + Collatz(3 * number + 1);
}

bool IsPrime(int number, int divisor = 2) {
  if (number == divisor) return true;
  if (!(number % divisor)) return false;
  return IsPrime(number, divisor + 1);
}

template <class T>
vector_t<T> Mergesort (vector_t<T> v) {
  if v.get_size() == 1 return v;
  vector_t<T> a, b;
  a.resize(v.get_size() / 2);
  for (int i = 0; i < get_size(); ++i) {
    a.at(i) = v.at(i);
  }
  b.resize(v.get_size() - a.get_size());
  for (int i = 0; i < get_size(); ++i) {
    b.at(i) = v.at(i);
  }
  Mergesort(a, b);
}

int main() {
  unsigned int number;
  std::cout << "[INPUT]: Introduce un número entero positivo > ";
  std::cin >> number;
  std::cout << "[INFO]: Numero de digitos del número " << number << ": "
            << NumberOfDigits(number) << std::endl;
  std::cout << "[INFO]: Suma de  los digitos del número " << number << ": "
            << SumOfDigits(number) << std::endl;
  std::cout << "[INFO]: Conversión del número" << number
            << " a binario: " << BinaryConversion(number) << std::endl;
  std::cout << "[INFO]: Longitud de Collatz para " << number << ": "
            << Collatz(number) << std::endl;
  std::cout << "[INFO]: El número es primo: " << (IsPrime(number) ? "SI" : "NO")
            << std::endl;
  return 0; 
}
