#include "mangoTree.h"
#include <iostream>

using namespace std;

mangoTree::mangoTree() {
	first = 0;
	last = 0;
}

int mangoTree::getCounter() {
	return mangoCounter;
}
void mangoTree::increaseCounter() {
	mangoCounter++;
}
void mangoTree::decreaseCounter() {
	mangoCounter--;
}

int mangoTree::addMangoFruit(mangoFruit* m) {

	if (first == 0) {
		first = m;
		last = m;
		increaseCounter();
	}
	else {
		last->next = m;
		m->prev = last;
		last = m;
		increaseCounter();
	}
	return 0;
}

int mangoTree::insertMangoFruit(mangoFruit* m, int pos) {
	if (pos <= 0)
		return -1;
	else if (pos > getCounter() + 1)
		return -1;
	else if (pos == getCounter() + 1) {
		addMangoFruit(m);
		return 0;
	}
	else {
		mangoFruit* tmp = first;
		int actualPosition = 1;

		while (actualPosition < pos) {
			tmp = tmp->next;
			actualPosition++;
		}
		if (tmp->prev == 0)
		{
			tmp->prev = m;
			first = m;
			m->next = tmp;
		}
		else {
			m->prev = tmp->prev;
			m->next = tmp;
			tmp->prev->next = m;
			tmp->prev = m;
		}
		return 0;
	}

}

int mangoTree::deleteMangoFruit(int pos) {
	if (pos < 0)
		return -1;
	else if (pos > getCounter())
		return -2;
	else if (pos <= getCounter()) {
		mangoFruit* tmp = first;
		int actualPosition = 1;

		while (actualPosition < pos) {
			tmp = tmp->next;
			actualPosition++;
		}
		if (tmp == first) {
			if (tmp->next == 0) {
				first = 0;
			}
			else {
				tmp->next->prev = 0;
				first = first->next;
			}

		}
		else if (tmp == last) {
			tmp->prev->next = 0;
			last = last->prev;

		}
		else {
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;

		}
		delete tmp;
		decreaseCounter();
	}
}

void mangoTree::printMangoWeight() {
	mangoFruit* tmp;
	tmp = this->first;
	int counter = 0;
	while (tmp != 0) {
		counter++;
		cout << "\nMango " << counter << "weight: " << tmp->getWeight();
		tmp = tmp->next;
	}
}

double mangoTree::mangoWeight(int pos) {
	mangoFruit * tmp = this->first;
	int counter = 0;
	while (tmp != 0) {
		if (counter == pos)
			return tmp->getWeight();
		counter++;
		tmp = tmp->next;
	}
}

mangoTree mangoTree::joinTrees(mangoTree Tree1, mangoTree Tree2) {

	if ((Tree1.mangoCounter + Tree2.mangoCounter) <= 6 && (Tree1.TotalWeight() + Tree2.TotalWeight()) <= 500) {
		mangoFruit * tmp = Tree2.first;
		while (tmp != 0) {
			Tree1.addMangoFruit(tmp);
			tmp = tmp->next;
		}
		join = 0;
		return Tree1;
	}
	join = 1;
	return Tree1;
}

double mangoTre