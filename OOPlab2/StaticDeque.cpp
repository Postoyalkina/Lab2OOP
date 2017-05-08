#include "stdafx.h"
#include "StaticDeque.h"

StaticDeque::StaticDeque(int s, int value)
{
	siz = s;
	arr = new int[siz];
	for (int i = 0; i < siz; i++)
	{
		arr[i] = value;
	}
}

StaticDeque::~StaticDeque()
{
	delete[] arr;
}

int StaticDeque::size() const
{
	return siz;
}

bool StaticDeque::isEmpty() const
{
	if (siz == 0) return true;
	else return false;
}

string StaticDeque::toString() const
{
	string str = "";
	for (int i = siz - 1; i >= 0; i--)
		str += arr[i] + 48;
	reverse(str.begin(), str.end());
	return str;
}

bool StaticDeque::pushFront(int value)
{
	int *tmp = new int[siz + 1];
	for (int i = 0; i < siz; i++)
		tmp[i+1] = arr[i];
	tmp[0] = value;
	delete[] arr;
	arr = tmp;
	siz++;
	return true;
}

bool StaticDeque::pushBack(int value)
{
	int *tmp = new int[siz + 1];
	for (int i = 0; i < siz; i++)
		tmp[i] = arr[i];
	tmp[siz] = value;
	delete[] arr;
	arr = tmp;
	siz++;
	return true;
}

int StaticDeque::popFront()
{
	int temp = arr[siz];
	int *tmp = new int[siz - 1];
	for (int i = 0; i < siz - 1; i++)
		tmp[i] = arr[i+1];
	delete[] arr;
	arr = tmp;
	siz--;
	return temp;
}

int StaticDeque::popBack()
{
	int temp = arr[siz];
	int *tmp = new int[siz - 1];
	for (int i = 0; i < siz - 1; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
	siz--;
	return temp;
}

int StaticDeque::peekFront() const
{
	return arr[0];
}

int StaticDeque::peekBack() const
{
	return arr[siz-1];
}
