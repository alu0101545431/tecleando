// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// COMENTARIOS: clase TAD cola implementada con un vector circular

#pragma once

#include <cassert>
#include <iostream>

#include "round_vector_t.h"

const unsigned char MAX_STACK_SIZE = 20;

using namespace std;

template <class T>
class queue_v_t {
 public:
  // constructor, constructor por defecto y destructor
  queue_v_t(const int);
  queue_v_t(void);
  ~queue_v_t(void);

  bool empty(void) const;
  bool full(void) const;
  int size(void) const;

  void push(const T& dato);
  void pop(void);
  const T& front(void) const;
  const T& back(void) const;
  queue_v_t<T> EvenOdd(void);

  void write(ostream& os = cout) const;

 private:
  round_vector_t<T> v_;
  int front_;
  int back_;
};

template <class T>
queue_v_t<T>::queue_v_t(const int max_sz) : v_(max_sz), front_(0), back_(-1) {}

template <class T>
queue_v_t<T>::queue_v_t(void) : v_(MAX_STACK_SIZE), front_(0), back_(-1) {}

template <class T>
queue_v_t<T>::~queue_v_t(void) {}

template <class T>
bool queue_v_t<T>::empty(void) const {
  return (back_ < front_);
}

template <class T>
bool queue_v_t<T>::full(void) const {
  return (size() >= v_.get_size() - 1);
}

template <class T>
int queue_v_t<T>::size(void) const {
  return back_ - front_ + 1;
}

template <class T>
void queue_v_t<T>::push(const T& dato) {
  assert(!full());
  back_++;
  v_.at(back_) = dato;
}

template <class T>
void queue_v_t<T>::pop(void) {
  assert(!empty());
  front_++;
}

template <class T>
const T& queue_v_t<T>::front(void) const {
  assert(!empty());
  return v_.at(front_);
}

template <class T>
const T& queue_v_t<T>::back(void) const {
  assert(!empty());
  return v_.at(back_);
}

template <class T>
void queue_v_t<T>::write(ostream& os) const {
  for (int i = back_; i >= front_; i--) os << v_.at(i) << " ";
  os << endl;
}

template <class T>
ostream& operator<<(ostream& os, const queue_v_t<T>& q) {
  q.write(os);
  return os;
}

// template <class T>
// queue_v_t<T> queue_v_t<T>::EvenOdd(void) {
//   T aux_value;
//   queue_v_t<T> aux_queue;
//   int size_q = size();
//   for (int i = 0; i < size_q; ++i) {
//     aux_value = front();
// 		pop();
//     if ((i + 1) % 2) {
//       push(aux_value);
//     } else {
//       aux_queue.push(aux_value);
//     }
//   }
// }


template <class T>
queue_v_t<T> queue_v_t<T>::EvenOdd(void) {
  T aux_value;
  queue_v_t<T> aux_queue;
  int size_q = size();
  for (int i = 0; i < size_q; ++i) {
    aux_value = front();
		pop();
    if ((i + 1) % 2) {
      push(aux_value);
    } else {
      aux_queue.push(aux_value);
    }
  }
}
