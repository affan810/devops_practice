#include "calculator.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
  ScientificCalculator calc;
  int choice;

  while (true) {
    cout << "\n=== Welcome to the Scientific Calculator ===" << endl;
    cout << "Please select an operation:" << endl;
    cout << "  1. Addition" << endl;
    cout << "  2. Subtraction" << endl;
    cout << "  3. Division" << endl;
    cout << "  4. Multiplication" << endl;
    cout << "  5. Factorial" << endl;
    cout << "  6. Square root" << endl;
    cout << "  7. Natural logarithm (ln)" << endl;
    cout << "  8. Power (x^b)" << endl;
    cout << "  9. Exit" << endl;
    cout << "Enter your choice (1-9): ";

    cin >> choice;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter a number between 1 and 6." << endl;
      continue;
    }

    if (choice == 9) {
      cout << "Thank you for using the calculator. Goodbye!" << endl;
      break;
    }

    try {
      if (choice == 1) {
        double num1, num2;
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        cout << "Sum: " << calc.add(num1, num2) << endl;
      } else if (choice == 2) {
        double num1, num2;
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        cout << "Difference: " << calc.subtract(num1, num2) << endl;
      } else if (choice == 3) {
        double numerator, denominator;
        cout << "Enter the numerator: ";
        cin >> numerator;
        cout << "Enter the denominator: ";
        cin >> denominator;
        cout << "Answer: " << calc.divide(numerator, denominator) << endl;
      } else if (choice == 4) {
        double num1, num2;
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        double result = calc.multiply(num1, num2);
        if (result > numeric_limits<double>::max()) {
          throw overflow_error("Multiplication overflow.");
        }
        cout << "Product: " << result << endl;
      } else if (choice == 5) {
        int n;
        cout << "Enter a non-negative integer (max 20): ";
        cin >> n;
        if (n > 20) {
          throw overflow_error(
              "Factorial too large (overflow risk). Max allowed = 20.");
        }
        cout << "Factorial: " << calc.factorial(n) << endl;
      } else if (choice == 6) {
        double x;
        cout << "Enter a non-negative number: ";
        cin >> x;
        cout << "Square root: " << calc.sqrt(x) << endl;
      } else if (choice == 7) {
        double x;
        cout << "Enter a positive number: ";
        cin >> x;
        cout << "Natural logarithm (ln): " << calc.ln(x) << endl;
      } else if (choice == 8) {
        double x, b;
        cout << "Enter the base (x): ";
        cin >> x;
        cout << "Enter the exponent (b): ";
        cin >> b;
        cout << "Power (x^b): " << calc.power(x, b) << endl;
      } else {
        cout << "Invalid choice. Please select a valid option (1-9)." << endl;
      }
    } catch (const exception &e) {
      cout << "Error: " << e.what() << endl;
    }
  }
  return 0;
}