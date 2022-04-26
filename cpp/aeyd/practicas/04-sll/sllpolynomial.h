// AUTOR: ADRIÁN LIMA GARCÍA
// FECHA: ADRIÁN LIMA GARCÍA
// EMAIL: ADRIANLIMAGARCIA00@ULL.EDU.ES
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
//

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <math.h>  // fabs, pow

#include <iostream>

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;           // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t(){};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial(){};

  // E/S
  void Write(std::ostream& = std::cout) const;

  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);
};

bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  for (int index = 0; index < v.get_size(); ++index) {
    if (fabs(v.at(v.get_size() - index - 1)) > eps) {
      push_front(new SllPolyNode(pair_double_t(v.at(v.get_size() - index - 1),
                                               v.get_size() - index - 1)));
    }
  }
}

// E/S
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1) os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  assert(!empty());
  SllPolyNode* aux = get_head();
  while (aux != NULL) {
    result += aux->get_data().get_val() * pow(x, aux->get_data().get_inx());
    aux = aux->get_next();
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol,
                            const double eps) const {
  bool differents = false;
  assert(!empty());
  SllPolyNode* aux = get_head();
  SllPolyNode* sllpol_aux = sllpol.get_head();
  while (aux != NULL && !differents) {
    if (fabs(aux->get_data().get_val() - sllpol_aux->get_data().get_val()) >
        eps) {
      differents = true;
    }
    aux = aux->get_next();
    sllpol_aux = sllpol_aux->get_next();
  }  // Recorrer la lista

  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol, SllPolynomial& sllpolsum,
                        const double eps) {
  SllPolyNode* first_node = new SllPolyNode;
  SllPolyNode* second_node = new SllPolyNode;
  SllPolyNode* last_node_placed = new SllPolyNode;
  bool is_first_element = true;

  first_node = get_head();
  second_node = sllpol.get_head();
  pair_double_t aux_pair;


  // MIENTRAS AMBAS LISTAS NO SE QUEDEN SIN NODOS . . .
  while (first_node != NULL && second_node != NULL) {
    // ASIGNACION DE PARES
    // Cuando hay 0's no se incluyen en SSL, entonces inx no coincide
    // Si coinciden, se suman ambos.
    // EL GRADO DE AMBOS MONOMIOS ES EL MISMO
    if (first_node->get_data().get_inx() == second_node->get_data().get_inx()) {
      aux_pair.set(
          first_node->get_data().get_val() + second_node->get_data().get_val(),
          first_node->get_data().get_inx());
      first_node = first_node->get_next();
      second_node = second_node->get_next();
      // Si inx del 2o mayor que 1o, hay 0 en el 1o, avanza 1o para equilibrar
      // EL GRADO DEL PRIMER MONOMIO A SUMAR ES MENOR QUE EL SEGUNDO
    } else if (first_node->get_data().get_inx() <
               second_node->get_data().get_inx()) {
      aux_pair.set(first_node->get_data().get_val(),
                   first_node->get_data().get_inx()); // Asignamos 1er nodo

      first_node = first_node->get_next();  // Solo avanza el 1o
      // Viceversa
    } else {
      aux_pair.set(second_node->get_data().get_val(),
                   second_node->get_data().get_inx());
      second_node = second_node->get_next();
    }
    // ASIGNACIÓN DE LOS PARES A UN NODO AUXILIAR PARA SU INSERCIÓN EN LISTA
    // DEPENDIENDO SI PROCEDE O NO (EPS)
    SllPolyNode* result_node = new SllPolyNode;
    result_node->set_data(aux_pair);
    if (fabs(result_node->get_data().get_val()) > eps) {
      if (is_first_element) {  // En el primer elemento lo que hacemos es
                               // ponerlo al principio.
        sllpolsum.push_front(result_node);
        is_first_element = false;  // Una vez hecho, seteamos a false.
      } else {  // Los siguientes casos se pondrán TRAS el primero (último)
        sllpolsum.insert_after(last_node_placed, result_node);
      }
      last_node_placed = result_node;
    }
  }
  // SE TERMINO LA PRIMERA LISTA
  // EL PROGRAMA SE LIMITA A PARTIR DE AHORA A IMPRIMIR LA SIGUIENTE
  while (first_node != NULL) {
    aux_pair.set(first_node->get_data().get_val(),
                 first_node->get_data().get_val());
    first_node = first_node->get_next();  // Solo avanza el 1o
    SllPolyNode* result_node = new SllPolyNode;
    result_node->set_data(aux_pair);
    sllpolsum.insert_after(last_node_placed, result_node);
  }
  // VICEVERSA
  while (second_node != NULL) {
    aux_pair.set(second_node->get_data().get_val(),
                second_node->get_data().get_inx());
    second_node = second_node->get_next();
    SllPolyNode* result_node = new SllPolyNode;
    result_node->set_data(aux_pair);
    sllpolsum.insert_after(last_node_placed, result_node);
  }
}

#endif  // SLLPOLYNOMIAL_H_
