from matplotlib.pyplot import get


class Polynomial():

  def __init__(self):
    self._polynomial = []

  def __init__(self, vector):
    self._polynomial = vector
  
  @property
  def GetPolynomial(self):
    return self._polynomial

  

  @property.setter
  

  # Operator overloading for polinomials
  def __add__(self, other):
    result = Polynomial()
    for i in range(BiggestRange(self, other)):
      result.AddValue((self._polynomial[i] or 0) + (other[i] or 0))
    return result

  def __sub__(self, other):
    pass

  # Methods

  # Returns the monomial for a given grade

  def GetValue(self, grade):
    return self._polynomial[grade]

  # Sets the value to a coefficient for a given grade
  def SetValue(self, grade, new_coefficient):
    self._polynomial[grade] = new_coefficient
  
  def AddValue(self, value):
    self._polynomial.append(value)

  def GetSize(self):
    return self._polynomial.length()

  def Negative(self):
    result = Polynomial()
    for i in self.GetSize():
      result.AddValue((-1) * self.GetValue(i))
    return result

def BiggestRange(first, second):
  if first.GetSize() < second.GetSize():
    return second.GetSize()
  return first.GetSize()
 