#include "Stack.h"

Stack::Stack() {
	top = 0;
	size = 5;
	counter = 0;
}

bool Stack::push(Node* _node) {
	if (top == 0) {
		top = _node;
		counter++;
		return true;
	}
	else {
		if(counter < size){
			_node->next = top;
			top = _node;
			counter++;
			return true;
		}
	}
	return false;
}

Node* Stack::pop() {
	if (top == 0)
		return 0;
	else {
		Node* tmp = top;
		top = tmp->next;
		tmp->next = 0;
		counter--;
		return tmp;
	}
}
