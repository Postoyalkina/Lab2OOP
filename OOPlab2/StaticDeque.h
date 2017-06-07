#pragma once
#include "Deque.h"
class StaticDeque: public Deque
{
private:
	int siz;
	int *arr;
public:
	StaticDeque(int s, int value);
	~StaticDeque();

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

