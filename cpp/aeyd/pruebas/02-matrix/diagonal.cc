/* 
  ADRIAN LIMA GARCIA
  Este ejercicio nos pide conseguir tanto la diagonal principal como la
  secundaria de una determinada matriz dada. En este caso nos ahorraremos
  un segundo bucle. Ya que por definición, la diagonal principal/sec de una
  determinada matriz cuadrada, posee los mismos índices, por lo que no tiene
  ningún sentido incrementar ambos por separado.
*/

#include <iostream>

int main(int argc, char const *argv[]) {
  const int dimension = 3;
  int B[dimension][dimension] = {{4, 5, 9}, {1, 7, 3}, {8, 6, 2}}; // matrix

  std::cout << "Principal diagonal's elements: " << std::endl;
  for (int i = 0; i < dimension; i++) {
    std::cout << B[i][i] << " "; // it'll give us 4 7 2
  }
  std::cout << std::endl;

  std::cout << "Secondary diagonal's elements: " << std::endl;
  for (int i = 0; i < dimension; i++) { // i increases to substract then
    std::cout << B[i][dimension - 1 - i] << " "; // we decrement by the substr of i
  // it'll give us 9 7 8 in this case
  }
  std::cout << std::endl;
  return 0;
}
