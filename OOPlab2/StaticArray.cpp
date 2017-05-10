#include "stdafx.h"
#include "StaticArray.h"


StaticArray::StaticArray(int s, int value)
{
	siz = s;
	arr = new int[siz];
	for (int i = 0; i < siz; i++)
	{
		arr[i] = value;
	}
}


StaticArray::~StaticArray()
{
	delete[] arr;
}

int StaticArray::size() const
{
	return siz;
}

bool StaticArray::isEmpty() const
{
	if (siz == 0) return true;
	else return false;
}

string StaticArray::toString() const
{
	string str = "";
	for (int i = siz - 1; i >= 0; i--)
		str += arr[i] + 48;
	reverse(str.begin(), str.end());
	return str;
}

int StaticArray::get(int index) const
{
	if (index > siz) throw 2;
	return arr[index];
}

void StaticArray::set(int index, int value)
{
	if (index > siz) throw 2;
	arr[index] = value;
}
