from matplotlib.pyplot import get


class Polynomial():

  # Constructor
  def __init__(self):
    self._polynomial = []

  def __init__(self, vector):
    self._polynomial = vector
  
  # Getters and Setters
  @property
  def polynomial(self):
    return self._polynomial

  @polynomial.setter
  def polynomial(self, new_polynomial):
    self._polynomial = new_polynomial
  
  # Operator overloading for polynomials
  
  def __add__(self, other):
    result = Polynomial()
    for i in range(BiggestRange(self, other)):
      result.AddValue((self._polynomial[i] or 0) + (other[i] or 0))
    return result

  def __sub__(self, other):
    return self + other.Negative()

  def __mul__(self, other):
    result = Polynomial()
    for i in range(BiggestRange(self, other)):
      result.AddValue(self.GetValue(i) * other)
    return result

  def __truediv__(self, other):
    result = Polynomial()
    for i in range(BiggestRange(self, other)):
      result.AddValue(self.GetValue(i) / other)
    return result


  # Methods

  # Returns the monomial for a given grade
  def GetValue(self, grade):
    return self._polynomial[grade]

  # Sets the value to a coefficient for a given grade
  def SetValue(self, grade, new_coefficient):
    self._polynomial[grade] = new_coefficient
  
  # Add a value to the last grade of polinomial
  def AddValue(self, value):
    self._polynomial.append(value)

  # Returns the size of the vector that represents a polinomial
  def GetSize(self):
    return self._polynomial.length()

  # Returns the inversed vector of the polinomial
  def Negative(self):
    result = Polynomial()
    for i in self.GetSize():
      result.AddValue((-1) * self.GetValue(i))
    return result

# Given 2 polinomials, returns the size of the biggest one.
def BiggestRange(first, second):
  if first.GetSize() < second.GetSize():
    return second.GetSize()
  return first.GetSize()
 