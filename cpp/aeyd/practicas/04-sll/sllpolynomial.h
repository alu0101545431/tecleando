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

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

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
    if (inx > 1)
      os << inx;
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
    if (fabs(aux->get_data().get_val() - sllpol_aux->get_data().get_val()) > eps) {
      differents =  true;
    }
    aux = aux->get_next();
    sllpol_aux = sllpol_aux->get_next();
  }

  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol,
			SllPolynomial& sllpolsum, const double eps) {
  SllPolyNode* first_node = new SllPolyNode;
  SllPolyNode* second_node = new SllPolyNode;
  SllPolyNode* aux = new SllPolyNode;
  bool is_first_element = true;

  first_node = get_head();
  second_node = sllpol.get_head();
  
  while(first_node != NULL && second_node != NULL ){ //Recorrer la lista
    pair_double_t aux_pair(first_node->get_data().get_val() + 
                          second_node->get_data().get_val(),
                          first_node->get_data().get_inx());
    SllPolyNode* third_node = new SllPolyNode;
    third_node->set_data(aux_pair); 
    if(is_first_element){ // En el primer elemento lo que hacemos es ponerlo al principio.
      sllpolsum.push_front(third_node);
      is_first_element = false; // Una vez hecho, seteamos a false.
    } else { // Los siguientes casos se pondrán TRAS el primero (último)
      sllpolsum.insert_after(aux, third_node); 
    }
    aux = sllpolsum.get_head();
    aux = third_node;
    first_node = first_node->get_next();
    second_node = second_node->get_next();
  }
}


// void SllPolynomial::Sum(const SllPolynomial& sllpol,
// 			SllPolynomial& sllpolsum,
// 			const double eps) {
//   SllPolyNode* aux = get_head();
//   SllPolyNode* sllpol_aux = sllpol.get_head();
//   pair_double_t aux_pair;
//   int list_index = 0;
//   int shortest_list_index = 0;
//   bool instance_is_shorter = false;
  
//   while (aux != NULL && sllpol_aux != NULL) {
    
//     aux_pair.set(aux->get_data().get_val() + sllpol_aux->get_data().get_val(), aux->get_data().get_inx());
//     sllpolsum.push_front(new SllPolyNode(aux_pair));
//     aux = aux->get_next();
//     sllpol_aux = sllpol_aux->get_next();
//     if (!(aux)) {
//       instance_is_shorter = true;
//     }
//     ++list_index;
//   }
  // SllPolyNode* shortest_list_node = (instance_is_shorter ? sllpol_aux : aux);
  // while (shortest_list_node != NULL) {
  //   if (shortest_list_index < list_index) {
  //     sllpolsum.push_front(shortest_list_node);
  //   }
  //   ++shortest_list_index;
  //   shortest_list_node = shortest_list_node->get_next();
  // }
// }
  

#endif  // SLLPOLYNOMIAL_H_
