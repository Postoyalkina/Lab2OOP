#pragma once
#include <string>

using namespace std;

class Container
{
public:
	Container();
	~Container();
	virtual int size() const=0;
	virtual bool isEmpty() const=0;
	virtual string toString() const=0;
};

