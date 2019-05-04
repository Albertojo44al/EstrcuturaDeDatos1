#pragma once
#include <iostream>

class vehicle{
public:
	int axes;
	vehicle();
	vehicle(int);
	vehicle* next;
	vehicle* prev;

	int getAxes();
	void setAxes(int);
};
