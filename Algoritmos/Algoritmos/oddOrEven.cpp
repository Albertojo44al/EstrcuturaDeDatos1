#include <iostream>

using namespace std;

bool oddOrEven(int number) {
	if (number - 2 == 0) {
		return true;
	}
	else if (number >= 2) {
		return oddOrEven(number - 2);
	}
	return false;
}

int main() {
	int number;
	cout << "Write a number: ";
	cin >> number;
	oddOrEven(number) ? cout << "\nThe number is Even" : cout << "\nThe number is odd";
}