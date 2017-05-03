#pragma once
#include "IndexedContainer.h"
class InsertableContainer: public virtual IndexedContainer
{
public:
	InsertableContainer();
	~InsertableContainer();
	virtual bool insertAt(int index, int value) =0;
	virtual int removeAt(int index) = 0;
};

