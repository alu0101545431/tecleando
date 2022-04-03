"""
PARTS OF A LINEAR PROGRAMMING PROBLEM:
  - OBJECTIVE FUNCTION (LIST OF INTS / RATIONALS) --> IMPLEMENT POLYNOMIAL VECTOR
  - RESTRICTIONS (LIST OF POLYNOMIAL VECTORS)
    - CONSTANTS (LAST ELEMENT OF EACH POLINOMIAL OF THE LIST)
    - TYPE OF RESTRICTION (STANDARD KIND BY NOW)

"""

class PSolver:
  def __init__(self):
    self._n_variables = None
    self._n_restrictions = None
    self._obj_f = None
    self._restrictions = []

  # Getters

  @parameter
  def n_variables(self):
    return self._n_variables

  @parameter
  def n_restrictions(self):
    return self._n_restrictions
  
  def obj_f(self):
    return self._obj_f

  def restrictions(self):
    return self.restrictions

  # Setters
  
  