// AUTOR: ADRIÁN LIMA GARCÍA
// FECHA: 28-03-2022
// EMAIL: ALU0101204147@ULL.EDU.ES
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol)
      : vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
 };


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  // MODIFICACION: Mostrar monomios con coeficiente 0
  void EmptyMonomials();
};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0};
  for (int i = 0; i < get_size(); ++i) {
    result += this->get_val(i) * pow(x, i);
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  for (int i = 0; i < get_size() && i < pol.get_size() && differents == false; i++) {  //Recorrer dos vectores, desde uno falle bandera arriba, abortamos bucle
    if (fabs(get_val(i) - pol.get_val(i)) > eps) { 
      differents = true; // comprobacion del igual por medio de epsilon
    }  
  }
  return !differents;
}





// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  for (int i = 0; i < get_nz(); ++i) {
    result += at(i).get_val() * pow( x, at(i).get_inx());
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol
			       , const double eps) const {
  bool differents = false;
  // Recorremos el vector incrementando el indice hasta la última posición
  // siempre y cuando esta sea menor que AMBOS, sino se aborta el bucle.
  // Además deben ser diferentes, si se detecta que son diferentes, aborta.
  for (int i = 0; i < get_nz() && i < spol.get_nz() && differents == false; ++i) { 
    // Comprobamos igualdad usando los distintos getters de los objetos por eps
    if (fabs(at(i).get_val() - spol.at(i).get_val()) > eps){
      differents = true;
    }  
  }
  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  for (int i = 0; i < get_nz() && i < pol.get_size() && differents == false; ++i) { 
  // Recorremos el vector incrementando el indice hasta la última posición
  // siempre y cuando esta sea menor que AMBOS, sino se aborta el bucle.
  // Además deben ser diferentes, si se detecta que son diferentes, aborta.
    if (fabs(at(i).get_val() < pol.get_val(at(i).get_inx()) > eps)){
      differents = true; // Compara posicion i con indice de la posicion i
    }
  }
  return !differents;
}

// MODIFICACION

void SparsePolynomial::EmptyMonomials() {
  int grade = 0;
  for (int i = 0; i < get_nz(); ++i) {  // se recorre vector escaso
    while (at(i).get_inx() != grade) {  // si el grado del par en el sp_vector
                                        // y el grado del pol normal NO coincide 
                                        // se incrementa el grado a comparar
      std::cout << "x" << grade << " "; // lo imprimimos
      ++grade;
    }
  ++grade;
  }
}


#endif  // POLYNOMIAL_H_
