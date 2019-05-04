#include "vehicle.h"

vehicle::vehicle(int _axes) {
	setAxes(_axes);
	next = 0;
	prev = 0;
}

vehicle::vehicle() {
	next = 0;
	prev = 0;
	setAxes(0);
}

int vehicle::getAxes() {
	return this->axes;
}

void vehicle::setAxes(int _axes) {
	this->axes = _axes;
}