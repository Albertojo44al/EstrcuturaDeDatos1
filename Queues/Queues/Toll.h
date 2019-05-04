#include "vehicle.h"

class Toll {

public:
	Toll();
	vehicle * first;
	vehicle * last;
	int Queue(vehicle *);
	int Dequeue(double);
	bool Empty();
	void Delete();
	void Print();
	int getAxes();
	int counter();
};
