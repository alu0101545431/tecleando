"""
PARTS OF A LINEAR PROGRAMMING PROBLEM:
  - OBJECTIVE FUNCTION (LIST OF INTS / RATIONALS) --> IMPLEMENT POLYNOMIAL VECTOR
  - RESTRICTIONS (LIST OF POLYNOMIAL VECTORS)
    - CONSTANTS (LAST ELEMENT OF EACH POLINOMIAL OF THE LIST)
    - TYPE OF RESTRICTION (STANDARD KIND BY NOW)

"""

import numbers
from polynomial import *


class PSolver:
  def __init__(self):
    self._number_of_variables = None # int
    self._n_restrictions = None # int
    self._objective_function = None # polynomial
    self._restrictions = [] # vector of polynomial

  # Getters

  @property
  def number_of_variables(self):
    return self._number_of_variables

  @property
  def n_restrictions(self):
    return self._n_restrictions
  
  @property
  def objective_function(self):
    return self._objective_function

  @property
  def restrictions(self):
    return self._restrictions

  # Methods

  @number_of_variables.setter
  def number_of_variables(self, other):
    self._number_of_variables = other

  @n_restrictions.setter
  def n_restrictions(self, other):
    self._n_restrictions = other
  
  @objective_function.setter
  def objective_function(self, other):
    self._objective_function = other

  @restrictions.setter
  def restrictions(self, other):
    self._restrictions = other


  # Add Restrictions
  def AddRestriction(self, restriction):
    self._restrictions.append(restriction)

  # Print the table  --  PENDING TO FORMAT
  def Print(self): 
    print("BV\t|\t", end = '')
    # - print the index of every x
    for i in range(self.number_of_variables):
      print("x{i}\t".format(i = i + 1), end = '')
    print("|\tCONST")
    for restriction in self.restrictions:
      print("xx\t|\t", end = '') # pending to add joining and leaving variables ...
      for coeficient in restriction.polynomial[:self.number_of_variables]:
        print("{coeficient}\t".format(coeficient = coeficient), end = '')
      print("|\t{coeficient}".format(coeficient = restriction.polynomial[self.number_of_variables]))
    
    

  # Setters
  
  