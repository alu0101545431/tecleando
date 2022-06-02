// EJEMPLOS DE PROBLEMAS DE BITSET. CÓDIGO INCOMPLETO

#include <iostream>

// Cargar en un objeto bitset el conjunto universal (111111...1)

void bitset_t::universal() {
  block_ = ~0;;
}


// Calcular el complemento de un conjunto (00110111 -> 11001000)
void bitset_t::complement() {
  block_ = ~block_;
}

// Calcular la intersección negada NAND y la unión negada NOR de dos conjuntos
void bitset_t::set_nand(const bitset_t& bs, bitset_t& result) const {
  result.block_ = ~(block_ & bs.block_);
}

// Calcular el valor medio de los elementos de un conjunto
float bitset_t::mean() {
  int n = 0, s = 0;
  for (int i = 1; i <= SIZE_U, ++i) {
    if (contains(i)) {
      s += i;
      n++;
    }
  }
  return (float) s/n;
}

// Mostrar por pantalla el producto cartesiano de dos conjuntos.
// Se llama producto cartesiano de AxB al conjunto de los pares de
// elementos (i, j) tales que i pertenece a A y j pertenece a B.

void bitset_t::prod_cart(const bitset_t& bs) const {
  for (int i = 1; i <= SIZE_U; ++i) {
    for (int j = 1; j <= SIZE_U; ++j) {
      if (bs.contains(j)) {
        std::cout << i << j;
      }
    }
  }
}
// 