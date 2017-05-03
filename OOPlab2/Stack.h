#pragma once
#include "PushPopContainer.h"
class Stack: PushPopContainer
{
private:
	struct Node
	{
		int value;
		Node *p;
	};
	Node *top;
	int siz;
public:
	Stack(int value);
	~Stack();

	int pop();
	bool push(int value);
	bool isEmpty() const;
	int size() const;
	string toString() const;
	int peek() const;
};

