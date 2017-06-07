#pragma once
#include "Container.h"
class IndexedContainer:public virtual Container
{
public:
	IndexedContainer();
	virtual ~IndexedContainer();
	virtual int get(int index) const = 0;
	virtual void set(int index, int value) = 0;
};

