from ast import Return
from multiprocessing.sharedctypes import Value
import re


class Rational():

  # Constructor --> Raise exception if den == 0
  def __init__(self, num, den):
      self._num = num
      self._den = den

  # Getters and setters --> Pending to raise exception in den setter != 0

  @property
  def num(self):
    return self._num

  @property
  def den(self):
    return self._den

  @property.setter
  def num(self, value):
    self._num = value

  @property.setter
  def den(self, value):
    self._den = value

  # Class methods

  def value(self):
    return self.num / self.den

  def opposite(self):
    return Rational(-1 * self.num, self.den)
  
  def reciprocal(self):
    return Rational(self.den, self.num)

  # Overloading operators

  def __add__(self, other):
    return Rational(self.num * other.den + self.den * other.num, self.den * other.den)
  
  def __sub__(self, other):
    return self + other.opposite()

  def __mul__(self, other):
    return Rational(self.num * other.num, self.den * other.den)

  def __truediv__(self, other):
    return self * other.reciprocal()
