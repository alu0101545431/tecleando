// AUTOR: ADRIÁN LIMA GARCÍA
// FECHA: ADRIÁN LIMA GARCÍA
// EMAIL: ADRIANLIMAGARCIA00@ULL.EDU.ES
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:

#ifndef SLLT_H_
#define SLLT_H_

#include <cassert>
#include <iostream>

#include "sll_node_t.h"

// Clase para almacenar una lista simplemente enlazada
template <class T>
class sll_t {
 public:
  // constructor
  sll_t(void) : head_(NULL) {}

  // destructor
  ~sll_t(void);

  // getters
  sll_node_t<T>* get_head(void) const { return head_; };

  bool empty(void) const;

  // operaciones
  void push_front(sll_node_t<T>*);
  sll_node_t<T>* pop_front(void);

  void insert_after(sll_node_t<T>*, sll_node_t<T>*);
  sll_node_t<T>* erase_after(sll_node_t<T>*);

  sll_node_t<T>* search(const T&) const;

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

  // PROBLEMAS

  void push_sorted(sll_node_t<T>*);
  void sort();

 private:
  sll_node_t<T>* head_;
};

// destructor
template <class T>
sll_t<T>::~sll_t(void) {
  while (!empty()) {
    sll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
}

// Comprobar si lista vacía
template <class T>
bool sll_t<T>::empty(void) const {
  return head_ == NULL;
}

// operaciones
template <class T>
void sll_t<T>::push_front(sll_node_t<T>* n) {
  assert(n != NULL);

  n->set_next(head_);
  head_ = n;
}

template <class T>
sll_node_t<T>* sll_t<T>::pop_front(void) {
  assert(!empty());
  sll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  aux->set_next(NULL);

  return aux;
}

template <class T>
void sll_t<T>::insert_after(sll_node_t<T>* prev, sll_node_t<T>* n) {
  assert(prev != NULL && n != NULL);

  n->set_next(prev->get_next());
  prev->set_next(n);
}

template <class T>
sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) {
  assert(!empty());
  assert(prev != NULL);
  sll_node_t<T>* aux = prev->get_next();

  assert(aux != NULL);
  prev->set_next(aux->get_next());
  aux->set_next(NULL);

  return aux;
}

template <class T>
sll_node_t<T>* sll_t<T>::search(const T& d) const {
  sll_node_t<T>* aux = head_;
  while ((aux != NULL) && (aux->get_data() != d)) aux = aux->get_next();

  return aux;
}

// E/S
template <class T>
std::ostream& sll_t<T>::write(std::ostream& os) const {
  sll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

// PROBLEMAS

// template <class T> void sll_t<T>::push_sorted(sll_node_t<T>* new_node) {
//   sll_node_t<T>* aux = get_head();
//   if (aux == NULL) push_front(new_node);
//   while (aux != NULL) {
//     std::cout << "a";
//     if (aux->get_next()->get_data() > new_node->get_data() && aux->get_next()
//     != NULL) {
//       std::cout << "b";
//       new_node->set_next(aux->get_next());
//       aux->set_next(new_node);
//       aux = new_node->get_next();
//     }
//     aux = aux->get_next();
//   }
// }
// a medias
// template <class T> void sll_t<T>::push_sorted(sll_node_t<T>* new_node) {
//   sll_node_t<T>* aux = get_head();
//   if (aux == NULL) push_front(new_node);
//   while (aux != NULL) {
//     std::cout << "a";
//     if (aux->get_next()->get_data() > new_node->get_data() && aux->get_next()
//     != NULL) {
//       std::cout << "b";
//       new_node->set_next(aux->get_next());
//       aux->set_next(new_node);
//       aux = NULL;
//     }
//     if (aux != NULL) aux = aux->get_next();
//   }
// }

// MI MANERA SIN FUNCIONAR 100%

// template <class T>
// void sll_t<T>::push_sorted(sll_node_t<T>* new_node) {
//   sll_node_t<T>* aux = get_head();
//   sll_node_t<T>* prev = NULL;
//   // lista vacia o 1er elemento
//   if (empty() || new_node->get_data() < aux->get_data()) {
//     push_front(new_node);
//     aux = NULL;
//   }
//   while (aux != NULL) {
//     // caso general
//     if (new_node->get_data() < aux->get_data()) {
//       insert_after(prev, new_node);
//       aux = NULL;
//     }
//     // recorrer lista
//     if (aux != NULL) {
//       prev = aux;
//       aux = aux->get_next();
//     }
//   }
// }

template <class T>
void sll_t<T>::push_sorted(sll_node_t<T>* n) {
  sll_node_t<T>* aux = head_;
  if (empty() || aux->get_data() > n->get_data()) {
    push_front(n);
  } else {
    while ((aux->get_next() != NULL) &&
           (n->get_data() > aux->get_next()->get_data())) {
      aux = aux->get_next();
    }
    if (aux == NULL) {
      aux->set_next(n);
      aux = aux->get_next();
      aux->set_next(NULL);
    } else {
      insert_after(aux, n);
    }
  }
}

template <class T>
void sll_t<T>::sort() {
  sll_t<T> sorted;
  sll_node_t<T>* aux = get_head();
  sll_node_t<T>* candidate = NULL;
  while (aux != NULL) {
    candidate = aux;
    aux = aux->get_next();
    sorted.push_sorted(candidate);
  }
  head_ = sorted.get_head();
  sorted.head_ = NULL;
}

#endif  // SLLT_H_
