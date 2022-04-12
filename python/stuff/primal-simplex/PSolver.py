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
  
  def objective_function(self):
    return self._objective_function

  def restrictions(self):
    return self._restrictions

  # Methods

  @property.setter
  def number_of_variables(self, other):
    self._number_of_variables = other

  @property.setter
  def n_restrictions(self, other):
    self._n_restrictions = other
  
  @property.setter
  def objective_function(self, other):
    self._objective_function = other

  @property.setter
  def restrictions(self, other):
    self._restrictions = other


  # Add Restrictions
  def AddRestriction(self, restriction):
    self._restrictions.append(restriction)

  # Print the table  --  PENDING TO FORMAT
  def Print(self): 
    print("BV\t|\t", end = '')
    # - 1 cause we dont want to use the constants yet
    for i in range(self.number_of_variables - 1):
      print("x{i}\t", end = '')
    print("|\t CONST\n")
    for restriction in range(self.restrictions):
      print("xx |", end = '')
      for coeficient in restriction:
        if coeficient == self.n_restrictions - 2:
          print("\t|\t")
        print("{coeficient}\t")
      print("|\t ")
    
    

  # Setters
  
  