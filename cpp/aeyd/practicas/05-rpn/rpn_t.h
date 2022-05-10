// AUTOR: ADRIAN LIMA GARCIA
// FECHA: 10 MAYO 2022
// EMAIL: ALU0101204147@ULL.EDU.ES
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <cctype>
#include <cmath>
#include <iostream>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T>
class rpn_t {
 public:
  // constructor
  rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private:
  T stack_;
  void operate_(const char operador);
};

// operaciones
template <class T>
const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) {
    char c = q.front();

    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      // poner código
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
                << "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  return stack_.top();
  // poner código
}

template <class T>
void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == 'l' ||
         c == '^'|| c == 'c' || c == 'r');
  int first_operator = 0, second_operator = 0;
  // poner código
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
    first_operator = stack_.top();
    std::cout << "   Sacamos de la pila un operando: " << first_operator
              << std::endl;
    stack_.pop();
    second_operator = stack_.top();
    std::cout << "   Sacamos de la pila otro operando: " << second_operator
              << std::endl;
    stack_.pop();
  } else if (c == 'c' || c == 'r' || c == 'l') {
    first_operator = stack_.top();
    std::cout << "   Sacamos de la pila el operando: " << first_operator
              << std::endl;
    stack_.pop();
  }
  switch (c) {
    case '+':
      stack_.push(first_operator + second_operator);
      break;
    // poner código resto de operadores
    case '-':
      stack_.push(second_operator - first_operator);  // preguntar tutorizada
      break;
    case '/':
      stack_.push(second_operator / first_operator);
      break;
    case '*':
      stack_.push(first_operator * second_operator);
      break;
    case '^':
      stack_.push(pow(second_operator, first_operator));
      break;
    case 'r':
      stack_.push(sqrt(first_operator));
      break;
    case 'l':
      stack_.push(log2(first_operator));
      break;
    case 'c':
      stack_.push(pow(first_operator, 2));
      break;
  }

  // poner código
  std::cout << "   Metemos en la pila el resultado: " << stack_.top()
            << std::endl;
}

#endif  // RPNT_H_
