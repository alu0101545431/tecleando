#pragma once

#include <iostream>

#include "bitset_t.hpp"
#include "vector_t.h"

class super_bitset_t {
 private:
  vector_t<AED::bitset_t> bytes_vector; // 64 bits vectors
 public:
  super_bitset_t(/* args */);

  void insert(const int);
  void remove(const int);
  
  ~super_bitset_t();
};
