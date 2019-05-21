#pragma once
#include "Node.h"
class Stack {
public:
	Stack();
	Node * top;
	int counter,size;
	bool push(Node*);
	Node* pop();
};