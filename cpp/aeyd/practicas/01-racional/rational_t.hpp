// AUTOR: Adrián Lima García
// FECHA: 22-02-2022
// EMAIL: alu0101204147@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  rational_t(const int = 0, const int = 1); // constructor que pone por defecto
                                            // numerador 0 y denominador 1
  ~rational_t() {} // destructor de la clase rational_t
  
  // pauta de estilo [71]: indentación a 2 espacios
  // getters
  int get_num() const; // método para acceder al contenido del denominador
  int get_den() const; // método para acceder al contenido del numerador
  
  // setters
  void set_num(const int); // método que modifica numerador de una instancia
  void set_den(const int); // método que modifica denominador de una instancia

  double value(void) const; // método que nos devuelve el valor del racional

  // FASE II
  // bool is_equal(const rational_t&, const double precision = EPSILON) const;
  // bool is_greater(const rational_t&, const double precision = EPSILON) const;
  // bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  // rational_t add(const rational_t&);
  // rational_t substract(const rational_t&);
  // rational_t multiply(const rational_t&);
  // rational_t divide(const rational_t&);
  
  void write(ostream& = cout) const; 
  void read(istream& = cin);
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_;
};
