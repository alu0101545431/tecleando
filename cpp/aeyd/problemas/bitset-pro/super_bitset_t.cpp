#pragma once

#include <iostream>

#include "super_bitset_t.hpp"
#include "vector_t.h"

namespace AED {
  void super_bitset_t::insert(const int element) {
    bytes_vector[element / SIZE_U].insert(element & SIZE_U);
  }
  void super_bitset_t::remove(const int element) {
    bytes_vector[element / SIZE_U].remove(element & SIZE_U);
  }
}