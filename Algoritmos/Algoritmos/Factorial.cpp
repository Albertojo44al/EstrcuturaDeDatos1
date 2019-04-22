#include <iostream>

using namespace std;

int factorial(int numero) {
	if (numero == 1)
		return 1;
	else
		return numero * factorial(numero - 1);
}

int main() {
	int number; 
	cout << "Write a number: ";
	cin >> number;
	cout << "the factorial is : " << factorial(number);
}