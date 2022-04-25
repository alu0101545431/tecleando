// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKV_H_
#define STACKV_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "vector_t.h"

#define MAX_STACK_SIZE 20

// Clase para pilas mediante estructura estática
template<class T> class stack_v_t {
 public:
  // constructores
  stack_v_t(int max_sz) : v_(max_sz), top_(-1) {}
  stack_v_t(void) : v_(MAX_STACK_SIZE), top_(-1) {}

  // destructor
  ~stack_v_t(void) {}

  // operaciones
  void push(const T& dato);
  void pop(void);
  const T& top(void) const;
  bool empty(void) const;
  bool full(void) const;
  void EndReplace(void);
  void reverse(stack_v_t&);

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  vector_t<T> v_;
  int         top_;
};


// operaciones
template<class T> void stack_v_t<T>::push(const T& dato) {
  assert(!full());
  v_[++top_] = dato;
}

template<class T> void stack_v_t<T>::pop(void) {
  assert(!empty());			
  top_--;
}

template<class T> const T& stack_v_t<T>::top(void) const {
  assert(!empty());
  return v_[top_];
}

template<class T> bool stack_v_t<T>::empty(void) const {
  return (top_ < 0);
}

template<class T> bool stack_v_t<T>::full(void) const {
  return (top_ == v_.get_size() - 1);
}

// E/S
template<class T> std::ostream& stack_v_t<T>::write(std::ostream& os) const {
  for(int i = top_; i >= 0; i--)
    os << " │ " << std::setw(2) << v_[i] << "  │" << std::endl;
  os << " └─────┘" << std::endl;
  return os;
}

template<class T>
void stack_v_t<T>::EndReplace() {
  T aux; // variable auxiliar para guardar el último valor
  T aux2; // variable para el penúltimo
  aux = top(); // se asigna
  pop(); // se elimina el ultimo elemento que ya guardamos en aux
  aux2 = top(); // idem al aux
  pop();
  push(aux);
  push(aux2);
}

template<class T>
void stack_v_t<T>::reverse(stack_v_t& new_stack) {
  while(!empty()) { // mientras no esté vacía
    new_stack.push(top()); // ponemos al principio de la nueva el final de la otra
    pop(); // eliminamos el final de la otra
  }
}


#endif  // STACKV_H_
