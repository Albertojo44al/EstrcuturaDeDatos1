#include "Toll.h"
#include "vehicle.h"
#include <iostream>

using namespace std;

int main() {
	Toll t;
	int option = 0;
	int axes,dequeue;
	double pay = 0;

	do {
		cout << "\n\n-------- Toll Menu --------";
		cout << "\n1. Queue \n2. Dequeue \n3. Print \n4.Exit";
		cout << "Write an option: ";
		cin >> option;
		switch (option)
		{
		case 1: 
		
			cout << "\n------ Queue ------";
			cout << "\nNumber of axes: ";
			cin >> axes;
			if (t.Queue(new vehicle(axes)) == 0)
				cout << "Entered vehicle.";
			break;
		case 2:
			
			cout << "\n------ Dequeue ------";
			cout << "\nNumber of axes: " << t.getAxes();
			cout << "\n2 axes pay 20 \n"
				<< "3 axes pay 30 \n"
				<< "4 axes pay 40 \n"
				<< "5 axes pay 50 \n"
				<< "6 or more axes pay 60";
			cout << "\nPay: ";
			cin >> pay;
			dequeue = t.Dequeue(pay);
			if (dequeue == -1) {
				cout << "\nThe dequeu is empty";
			}
			else if (dequeue == -2) {
				cout << "\nThe payment is incorrect.";
			}else {
				cout << "\nThe payment was complete.";
			}
			break;
		case 3:
			cout << "\n-------- Print ---------\n";
			t.Print();
			break;
		case 4:
			cout << "\nLeaving the system...";
			break;
		}
	
	} while (option != 4);

}