#pragma once

#include <cassert>
#include <iostream>

using namespace std;

template <class T>
class vector_t {
 public:
  vector_t(const int = 0);
  ~vector_t();
  void resize(const int);

  // getters
  T get_val(const int) const;
  int get_size(void) const;

  // setters
  void set_val(const int, const T);

  // getters-setters
  T& at(const int);
  T& operator[](const int);

  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;
  void write(ostream& = cout) const;
  void read(istream& = cin);

  // MODIFICACION
  bool IsPalindromic();

  // PROBLEMAS TEMA 2

  void Reverse();

 private:
  T* v_;
  int sz_;
  void build(void);
  void destroy(void);
};

template <class T>
vector_t<T>::vector_t(const int n) {
  sz_ = n;
  build();
}

template <class T>
vector_t<T>::~vector_t() {
  destroy();
}

template <class T>
void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template <class T>
void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template <class T>
void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}

template <class T>
inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T>
inline int vector_t<T>::get_size() const {
  return sz_;
}

template <class T>
void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

template <class T>
T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T>
T& vector_t<T>::operator[](const int i) {
  return at(i);
}

template <class T>
const T& vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T>
const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}

template <class T>
void vector_t<T>::write(ostream& os) const {
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++) os << at(i) << "\t";
  os << endl;
}

template <class T>
void vector_t<T>::read(istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i) is >> at(i);
}

// FASE II: producto escalar
template <class T>
T scal_prod(const vector_t<T>& v, const vector_t<T>& w) {
  assert(w.get_size() ==
         v.get_size());  // nos aseguramos que tienen el mismo tamaño
  T result;
  for (int i = 0; i < v.get_size(); ++i) {
    result =
        result + (v.get_val(i) * w.get_val(i));  // hacemos la suma de producto
  }
  return result;
}

double scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w) {
  assert(w.get_size() ==
         v.get_size());  // nos aseguramos que tienen el mismo tamaño
  double result;
  for (int i = 0; i < v.get_size(); ++i) {
    result = result + (v.get_val(i).value() *
                       w.get_val(i).value());  // hacemos la suma de producto
  }
  return result;
}

// MODIFICACION
template <class T>
bool vector_t<T>::IsPalindromic() {
  int vector_size = get_size();  // seteamos a una variable temp
  for (int i = 0; i < vector_size; ++i) {
    if (!(get_val(i) == get_val(vector_size - i - 1))) {  // comparo 1a y ult
      return false;  // si no es par, hacemos break de la funcion
    }
  }
  return true;
}

// HOJA 3
template <class T>
void vector_t<T>::Reverse() {
  for (int index = 0; index < get_size(); ++index) {
    std::cout << at(get_size() - index - 1) << " ";
  }
  std::cout << std::endl;
}
