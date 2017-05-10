#include "stdafx.h"
#include "Stack.h"
#include <string>

using namespace std;

Stack::Stack(int value)
{
	top = new(Node); 
	top->value = value; 
	top->p = 0;
	siz = 1; 

}
Stack::~Stack()
{
	while (top)
	{
		Node *ps = top;
		top = top->p;
		delete ps;
	}
}

bool Stack::push(int value)
{
	siz++;
	Node *ps = new Node;
	ps->value = value;
	ps->p = top;
	top = ps;
	return true;
}

int Stack::pop()
{
	if (isEmpty()) throw 1;
	siz--;
	int temp = top->value;
	Node *ps = top;
	top = top->p;
	delete ps;
	return temp;
}

int Stack::peek() const
{
	if (isEmpty()) throw 1;
	else return top->value;
}

bool Stack::isEmpty() const
{
	if (siz == 0) return true;
	else return false;
}

int Stack::size() const
{
	return siz;
}

string Stack::toString() const
{
	int i = 0;
	string str = "";
	Node *top1 = top;
	while (top1)
	{
		str += top1->value + 48;
		top1 = top1->p;
		i++;
	}
	reverse(str.begin(), str.end());
	return str;
}