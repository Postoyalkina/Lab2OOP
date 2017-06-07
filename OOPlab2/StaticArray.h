#pragma once
#include "IndexedContainer.h"
class StaticArray: public IndexedContainer
{
private:
	int siz;
	int *arr;
public:
	StaticArray(int s, int value);
	~StaticArray();
	int size() const;
	bool isEmpty() const;
	string toString() const;
	int get(int index) const;
	void set(int index, int value);
};

