#include "mangoFruit.h"
#include <iostream>

mangoFruit::mangoFruit(double w) {
	setWeight(w);
	next = 0;
	prev = 0;
}

mangoFruit::mangoFruit() {
	setWeight(0);
	next = 0;
	prev = 0;
}
void mangoFruit::setWeight(double w) {
	weight = w - (0.1 * w);
}
double mangoFruit::getWeight() {
	return weight;
}

