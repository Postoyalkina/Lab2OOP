#pragma once
#include "Container.h"
class PushPopContainer: public virtual Container
{
public:
	PushPopContainer();
	~PushPopContainer();
	virtual bool push(int value) = 0;
	virtual int pop() = 0;
	virtual int peek() const = 0;
};

