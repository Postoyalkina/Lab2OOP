#pragma once
#include "PushPopContainer.h"
class Queue: public PushPopContainer
{
private:
	struct Node
	{
		int value;
		Node *p;
	};
	Node *head, *tail;
	int siz;

public:
	Queue();
	Queue(int value);
	~Queue();

	int pop();
	bool push(int value);
	bool isEmpty() const;
	int size() const;
	string toString() const;
	int peek() const;
};

