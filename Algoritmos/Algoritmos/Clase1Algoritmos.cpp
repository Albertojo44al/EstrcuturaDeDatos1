#include <iostream>

using namespace std;

int factorial(int numero) {
	int factorial = 1;
	while (numero > 0) {
		factorial = factorial * numero;
		numero--;
	}
	return factorial;
}
bool parImpar(int numero) {
	if (numero - 2 == 0) {
		return true;
	}
	else if (numero >= 2) {
		return parImpar(numero - 2);
	}
	return false;
}

bool numeroPrimo(int numero) {
	int r = 0;
	for (int i = 1; i < (numero + 1); i++) {
		if (numero%i == 0)
			r++;
	}
	if (r != 2)
		return false;
	return true;
}


int main() {
	int numero = 0, opcion = 0;
	do {
		cout << "\n\n1. Factorial \n2.Numeros Pares \n3.Numeros Primos \n4.Salir";
		cout << "\nIngrese una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			cout << "\nIngrse un numero :";
			cin >> numero;
			cout << "\nEl factorial es: " << factorial(numero);
			break;
		case 2:
			cout << "\nIngrse un numero :";
			cin >> numero;
			parImpar(numero) ? cout << "\nEs Par" : cout << "\nEs Impar";
			break;
		case 3:
			cout << "\nIngrse un numero :";
			cin >> numero;
			numeroPrimo(numero) ? cout << "\nEs Primo" : cout << "\nNo es Primo";
			break;
		}

	} while (opcion != 4);
}