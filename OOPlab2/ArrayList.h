#pragma once
#include "PushPopContainer.h"
#include "InsertableContainer.h"
class ArrayList: PushPopContainer, InsertableContainer
{
private:
	const int sizOf = 3;
	int siz;
	int *arr;
public:
	ArrayList();
	ArrayList(int Value);

	~ArrayList();
	int pop();
	bool push(int value);
	bool insertAt(int index, int value);
	int removeAt(int index);
	int peek() const;
	int size() const;
	bool isEmpty() const;
	string toString() const;
	int get(int index) const;
	void set(int index, int value);
};

