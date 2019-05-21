#pragma once
#include <iostream>

class mangoFruit {

public:
	double weight;
	mangoFruit();
	mangoFruit(double w);
	mangoFruit* next;
	mangoFruit* prev;
	double getWeight();
	void setWeight(double w);


};

