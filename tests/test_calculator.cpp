#include <cassert>
#include <iostream>

// include calculator functions
#include "../src/calculator.h"

int main() {
  ScientificCalculator calc;
  assert(calc.add(2, 3) == 5);
  assert(calc.subtract(10, 4) == 6);
  assert(calc.multiply(3, 5) == 15);
  assert(calc.divide(10, 2) == 5);

  // Factorial tests
  assert(calc.factorial(0) == 1);
  assert(calc.factorial(5) == 120);
  assert(calc.factorial(10) == 3628800);

  // Square root tests
  assert(calc.sqrt(4) == 2);
  assert(calc.sqrt(9) == 3);

  // Natural logarithm tests
  assert(std::abs(calc.ln(1) - 0) < 1e-9);
  assert(std::abs(calc.ln(2.718281828459045) - 1) < 1e-9);

  // Power function tests
  assert(calc.power(2, 3) == 8);
  assert(calc.power(5, 0) == 1);
  assert(calc.power(9, 0.5) == 3);
  assert(calc.power(9, 2) == 81);

  std::cout << "All arithmetic and scientific tests passed successfully!"
            << std::endl;

  return 0;
}