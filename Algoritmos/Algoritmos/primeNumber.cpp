#include <iostream>

using namespace std;

int main() {
	int number, aux =0;
	cout << "Write a number: ";
	cin >> number;
	for (int i = 1; i < (number + 1); i++) {
		if (number%i == 0)
			aux++;
	}
	if (aux != 2)
		cout << "\nIs not prime";
	cout << "\nThe number is prime";
}
