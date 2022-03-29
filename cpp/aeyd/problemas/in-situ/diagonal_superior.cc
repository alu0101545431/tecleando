#include <iostream>

int main(int argc, char const *argv[]) {
  int m = 3;
  int matrix[m][m] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };

  for (int i = 0; i < m; i++) {
    for (int j = i; j < m; j++) {
      if (!(matrix[i][j] == matrix[j][i])) {
        std::cout << "FALSE" << std::endl;
        break;
      }
    }
  }
  std::cout << "TRUE" << std::endl;
  return 0;
}
