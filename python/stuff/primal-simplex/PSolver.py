"""
PARTS OF A LINEAR PROGRAMMING PROBLEM:
  - OBJECTIVE FUNCTION (LIST OF INTS / RATIONALS) --> IMPLEMENT POLYNOMIAL VECTOR
  - RESTRICTIONS (LIST OF POLYNOMIAL VECTORS)
    - CONSTANTS (LAST ELEMENT OF EACH POLINOMIAL OF THE LIST)
    - TYPE OF RESTRICTION (STANDARD KIND BY NOW)

"""

from inspect import property
from polynomial import *


class PSolver:
  def __init__(self):
    self._n_variables = None # int
    self._n_restrictions = None # int
    self._obj_f = None # polynomial
    self._restrictions = [] # vector of polynomial

  # Getters

  @property
  def n_variables(self):
    return self._n_variables

  @property
  def n_restrictions(self):
    return self._n_restrictions
  
  def obj_f(self):
    return self._obj_f

  def restrictions(self):
    return self._restrictions

  # Methods

  @property.setter
  def n_variables(self, other):
    self._n_variables = other

  @property.setter
  def n_restrictions(self, other):
    self._n_restrictions = other
  
  @property.setter
  def obj_f(self, other):
    self._obj_f = other

  @property.setter
  def restrictions(self, other):
    self._restrictions = other


  # Add Restrictions
  def AddRestriction(self, restriction):
    self._restrictions.append(restriction)

  # Print the table  --  PENDING TO FORMAT
  def Print(self): 
    print("BV\t|\t", end = '')
    for i in range(self.n_variables):
      print("{i}\t", end = '')
    print("|\t CONST")
    
    

  # Setters
  
  