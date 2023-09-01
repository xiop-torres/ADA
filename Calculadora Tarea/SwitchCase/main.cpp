#include <iostream>
using namespace std;
int main() {
  char operador;
  float num1, num2, resultado;

  cout << "Ingrese un operador(+ , - , * , /) : ";
  cin >> operador;

  cout << "Ingrese el primer numero : ";
  cin >> num1;
  cout << endl;
  cout << "Ingres el segundo numero : ";
  cin >> num2;

  switch (operador) {
  case '+':
    resultado = num1 + num2;
    break;
  case '-':
    resultado = num1 - num2;
    break;
  case '*':
    resultado = num1 * num2;
    break;
  case '/':
    if (num2 != 0) {
      resultado = num1 / num2;
    } else {
      cout << "No se puede dividir por cero" << endl;
      return 1;
    }
    break;
  }

  cout << "El resultado es : " << resultado << endl;
}