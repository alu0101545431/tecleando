#include <iostream>
#include <string>
#include <fstream>

/*
 * @brief Check whether two files are equal or not
 * @param file: the name of the first file to compare
 * @param file2: the second one
 * @return -1 if the files are equal or the line number if they are not
 */
int Find(std::ifstream& file, std::ifstream& file2);