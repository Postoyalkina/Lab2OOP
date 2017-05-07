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
	delete[] arr;
}

int ArrayList::pop()
{
	int temp = arr[siz];
	int *tmp = new int[siz - 1];
	for (int i = 0; i < siz-1; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
	siz--;
	return temp;
}

bool ArrayList::push(int value)
{
	int *tmp = new int [siz + 1];
	for (int i = 0; i < siz; i++)
		tmp[i] = arr[i];
	tmp[siz] = value;
	delete[] arr;
	arr = tmp;
	siz++;
	return true;
}

bool ArrayList::insertAt(int index, int value)
{
	int *tmp = new int[siz + 1];
	int i = 0;
	while(i!=index)
	{
		tmp[i] = arr[i];
		i++;
	}
	tmp[index] = value;
	while (index <= siz)
	{
		tmp[index + 1] = arr[index];
		index++;
	}
	delete[] arr;
	arr = tmp;
	siz++;
	return true;
}

int ArrayList::removeAt(int index)
{
	int *tmp = new int[siz - 1];
	int i = 0;
	while (i != index)
	{
		tmp[i] = arr[i];
		i++;
	}
	while (index < siz-1)
	{
		tmp[index] = arr[index+1];
		index++;
	}
	delete[] arr;
	arr = tmp;
	siz--;
	return 0;
}

int ArrayList::peek() const
{
	return arr[siz-1];
}

int ArrayList::size() const
{
	return siz;
}

bool ArrayList::isEmpty() const
{
	if (siz == 0) return true;
	else return false;
}

string ArrayList::toString() const
{
	string str = "";
	for (int i = siz-1; i >= 0; i--)
		str += arr[i]+48;
	reverse(str.begin(), str.end());
	return str;
}

int ArrayList::get(int index) const
{
	return arr[index];
}

void ArrayList::set(int index, int value)
{
	arr[index] = value;
}
