#include <iostream>

using namespace std;

int main() {
	int number, factorial = 1;
	cout << "Write a number: ";
	cin >> number;
	while (number > 0) {
		factorial = factorial * number;
		number--;
	}
	cout << "the factorial is : " << factorial;
}