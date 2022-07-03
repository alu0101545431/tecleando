#include <vector>
#include <fstream>

#ifndef MY_WC
#define MY_WC

void Usage(int argc, const char* argv[]);
std::vector<int>& WordCount(const std::string& path_input_file);


#endif