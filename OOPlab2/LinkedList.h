#pragma once
#include "PushPopContainer.h"
#include "InsertableContainer.h"
class LinkedList: PushPopContainer, InsertableContainer
{
private:
	struct Node
	{
		int value;
		Node *p, *n;
	};
	Node *head, *tail;
	int siz = 0;
public:
	LinkedList();
	LinkedList(int value);
	~LinkedList();
	int pop();
	bool push(int value);
	bool insertAt(int index, int value);
	int removeAt(int index);
	int peek() const;
	int size() const;
	bool isEmpty() const ;
	string toString() const ;
	int get(int index) const;
	void set(int index, int value);
};

