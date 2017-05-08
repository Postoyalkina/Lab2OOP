#pragma once
#include "Deque.h"
class LinkedDeque: Deque
{
private:
	struct Node
	{
		int value;
		Node *p, *n;
	};
	Node *head, *tail;
	int siz;
public:
	LinkedDeque();
	LinkedDeque(int value);
	~LinkedDeque(); 
	int size() const;
	bool isEmpty() const;
	string toString() const;
	bool pushFront(int value);
	bool pushBack(int value);
	int popFront();
	int popBack();
	int peekFront() const;
	int peekBack() const;
};

