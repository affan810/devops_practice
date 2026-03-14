#include "calculator.h"
#include <cmath>

double ScientificCalculator::add(double a, double b) { return a + b; }

double ScientificCalculator::subtract(double a, double b) { return a - b; }

double ScientificCalculator::multiply(double a, double b) { return a * b; }

double ScientificCalculator::divide(double a, double b) {
  if (b == 0)
    throw std::invalid_argument("Cannot divide by zero.");
  return a / b;
}

unsigned long long ScientificCalculator::factorial(int n) {
  if (n < 0)
    throw std::invalid_argument("Factorial undefined for negative values.");
  unsigned long long result = 1;
  for (int i = 2; i <= n; i++)
    result *= i;
  return result;
}

double ScientificCalculator::sqrt(double x) {
  if (x < 0)
    throw std::invalid_argument("Square root undefined for negative values.");
  return std::sqrt(x);
}

double ScientificCalculator::ln(double x) {
  if (x <= 0)
    throw std::invalid_argument(
        "Natural logarithm undefined for non-positive values.");
  return std::log(x);
}

double ScientificCalculator::power(double x, double b) {
  return std::pow(x, b);
}