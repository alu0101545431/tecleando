// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// COMPILACIÓN: g++ -g main_stack.cc -o main_stack
// EJECUCIÓN: ./main_stack

#include <iostream>

#include "matrix_t.hpp"
#include "queue_l_t.h"
#include "queue_v_t.h"
#include "sll_node_t.h"
#include "sll_t.h"
#include "stack_l_t.h"
#include "stack_v_t.h"

using namespace std;

void base(const unsigned n, const unsigned short b, queue_v_t<unsigned>& q) {
  if (n / b < b) {
    q.push(n % b);
    q.push(n / b);
  } else {
    q.push(n % b);
    base(n / b, b, q);
  }
}

int main(void) {
  stack_v_t<char> pila_vector;
  cout << "********** PILA VECTOR **********" << endl;
  for (int i = 0; i < 10; i++) {
    pila_vector.push('a' + i);
    cout << endl;
  }
  cout << endl;

  // stack_l_t<char> pila_lista;
  // cout << "********** PILA LISTA **********" << endl;
  // for (int i = 0; i < 10; i++) {
  //   pila_lista.push('a' + i);
  //   pila_lista.write();
  //   cout << endl;
  // }
  // cout << endl;

  // EJERCICIOS EXAMEN UWU
  cout << ".................." << endl;
  pila_vector.reverse();
  pila_vector.write();

  // SARRUS
  // matrix_t<int> uwu;
  // cout << "INTRODUCE [FILAS] [COLUMNAS] enter, fila a fila > ";
  // uwu.read();
  // uwu.write();
  // std::cout << "determinante" << uwu.Sarrus();

  queue_v_t<unsigned> bin;
  std::cout << "convert" << std::endl;
  base(100, 8, bin);
  bin.write();

  sll_t<int> orden;
  orden.push_front(new sll_node_t<int>(4));
  orden.push_front(new sll_node_t<int>(8));
  orden.push_front(new sll_node_t<int>(6));
  orden.push_front(new sll_node_t<int>(9));
  orden.push_front(new sll_node_t<int>(2));

  // Prueba copiar
  cout << "Ordenar listas" << endl;
  // orden.push_sorted(new sll_node_t<int>(4));
  cout << "a";
  orden.sort();
  cout << "a";
  orden.write();
  cout << endl;

  return 0;
}
