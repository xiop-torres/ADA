#include <iostream>
using namespace std;
// Declaración de funciones para operaciones matemáticas
double suma(double a, double b) { return a + b; }
double resta(double a, double b) { return a - b; }
double multiplicacion(double a, double b) { return a * b; }
double division(double a, double b) {
  if (b != 0) {
    return a / b;
  } else {
    cout << "Error No se puede dividir por cero." << endl;
    return 0.0;
  }
}

int main() {
  // Declaración de punteros a funciones
  double (*operacion)(double, double);

  double num1, num2;
  char operador;

  std::cout << "Ingrese dos números: ";
  std::cin >> num1 >> num2;

  std::cout << "Elija una operación (+, -, *, /): ";
  std::cin >> operador;

  // Asigna el puntero a la función correspondiente según la operación
  // seleccionada
  switch (operador) {
  case '+':
    operacion = suma;
    break;
  case '-':
    operacion = resta;
    break;
  case '*':
    operacion = multiplicacion;
    break;
  case '/':
    operacion = division;
    break;
  default:
    cout << "Operación no válida." << endl;
    return 1;
  }

  // Realiza la operación y muestra el resultado
  double resultado = operacion(num1, num2);
  std::cout << "Resultado: " << resultado << std::endl;

  return 0;
}
