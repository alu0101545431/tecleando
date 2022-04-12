from PSolver import *
from polynomial import *

objective_function = Polynomial([4, -2, 2])

restriction_one = Polynomial([0, 6, 1, 4])
restriction_two = Polynomial([1, -2, 0, 2])

problem = PSolver()

problem.objective_function = objective_function
problem.n_restrictions = 2
problem._number_of_variables = 3
problem.AddRestriction(restriction_one)
problem.AddRestriction(restriction_two)

problem.Print()


