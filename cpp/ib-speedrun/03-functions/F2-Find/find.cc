#include "find.h"

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>


/*
 * @brief Check whether two files are equal or not
 * @param file: the name of the first file to compare
 * @param file2: the second one
 * @return -1 if the files are equal or the line number if they are not
 */
int Find(std::ifstream& file, std::ifstream& file2) {
  int line_counter = 0;
  std::string line = "", line2 = "";
  while (getline(file, line) && getline(file2, line2)) {
    ++line_counter;
    if (line != line2) return line_counter;
  }
  if (!(getline(file, line) && getline(file2,line2))) {
    return ++line_counter;
  }
  return 0;
}
