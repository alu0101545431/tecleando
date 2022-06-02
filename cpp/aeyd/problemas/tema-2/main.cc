// g++ -g rational_t.cpp main.cc -o main.out

#include <iostream>
#include <cmath>

#include "rational_t.hpp"

#include "vector_t.h"

#include "matrix_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3);

  // FASE I
  cout << "a + b: ";
  (a+b).write();

  cout << "b - a: ";
  (b-a).write();

  cout << "a * b: ";
  (a*b).write();
  
  cout << "a / b: ";
  (a/b).write();
  
  cout << endl;
  
  // FASE II
  vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();
  
  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl;
  
  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << endl;
  
  
  // FASE III
  matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();
  
  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write();
  

// MODIFICACION
  vector_t<int> vector_modificacion;
  cout << "MODIFICACION: Introduce el vector" << endl;
  vector_modificacion.read();
  cout << "Vector: " << endl;
  vector_modificacion.write();
  if (vector_modificacion.IsPalindromic()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  // HOJA DE PROBLEMAS
  // invertir elementos de un vector

  // v.write();
  // v.Reverse();
  int search_value = 2;
  cout << "[INFO]: Valor a buscar... > " << search_value << " -- POSICIÓN: ";
  cout << vector_modificacion.Search(search_value) << endl;
  cout << "[INFO]: Numero de valores mayores o iguales que... > " << search_value << " -- RESPUESTA: ";
  cout << vector_modificacion.HigherOrEqualThan(search_value) << endl;

  
  


  return 0;
}


