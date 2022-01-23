#include <iostream>
#include <string>

#include "books.h"

int main(int argc, char const *argv[]) {
  Usage(argc, argv);
  int taxes = std::stoi(argv[1]);
  Book first_book("El quijote de la Mancha", 1605, 21.0);
  Book second_book("El lazarillo de Tormes", 1554, 18.0);
  Book third_book("Los pilares de la Tierra", 1989, 27.0);
  std::cout << first_book.GetName() << ", " << first_book.GetYear() << " "
            << first_book.GetYear() << ", " << first_book.PriceWithTaxes(taxes)
            << std::endl;
  return 0;
}