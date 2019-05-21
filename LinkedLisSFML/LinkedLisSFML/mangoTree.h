#pragma once
#include <iostream>
#include "mangoFruit.h"

using namespace std;

class mangoTree {
public:
	int join;
	int mangoCounter;
	void increaseCounter();
	void decreaseCounter();
	mangoTree joinTrees(mangoTree, mangoTree);
	mangoFruit* first;
	mangoFruit* last;
	mangoTree();
	int addMangoFruit(mangoFruit* m);
	int insertMangoFruit(mangoFruit* m, int position);
	int deleteMangoFruit(int position);
	double TotalWeight();
	void printMangoWeight();
	int getCounter();
	double mangoWeight(int pos);
};