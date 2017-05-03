#include "stdafx.h"
#include "ArrayList.h"


ArrayList::ArrayList()
{
	siz = sizOf;
	arr = new int[siz];
}

ArrayList::ArrayList(int value)
{
	siz = sizOf;
	arr = new int[siz];
	for (int i = 0; i < siz; i++)
	{
		arr[i] = value;
	}
}

ArrayList::~ArrayList()
{
}

int ArrayList::pop()
{
	return 1;
}

bool ArrayList::push(int value)
{
	return true;
}

bool ArrayList::insertAt(int index, int value)
{
	return false;
}

int ArrayList::removeAt(int index)
{
	return 0;
}

int ArrayList::peek() const
{
	return 0;
}

int ArrayList::size() const
{
	return 0;
}

bool ArrayList::isEmpty() const
{
	return false;
}

string ArrayList::toString() const
{
	return string();
}

int ArrayList::get(int index) const
{
	return 0;
}

void ArrayList::set(int index, int value)
{
}
