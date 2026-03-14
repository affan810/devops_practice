#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdexcept>

class ScientificCalculator {
public:
  double add(double a, double b);
  double subtract(double a, double b);
  double multiply(double a, double b);
  double divide(double a, double b);

  unsigned long long factorial(int n);
  double sqrt(double x);
  double ln(double x);
  double power(double x, double b);
};

#endif