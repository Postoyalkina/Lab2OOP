#include "stdafx.h"
#include "Stack.h"
#include <string>

using namespace std;

Stack::Stack(int value)
{
	top = new(Node); 
	top->value = value; // ЗАписываем значение
	top->p = 0; // Адрес ноль, так как это хвост стека - элемент добавленный первым
	siz = 1; // После выделения памяти и заполянения полей структуры стек стал иметь размер 1

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

int Stack::pop()
{
	siz--;
	if (isEmpty()) return -1;
	int temp = top->value;
	Node *ps = top;
	top = top->p;
	delete ps;
	return temp;
}

bool Stack::push(int value)
{
	siz++;
	Node *ps = new Node;
	ps-> value = value;
	ps->p = top;
	top = ps;
	return true;
}

bool Stack::isEmpty() const
{
	if (top == nullptr) return true;
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

int Stack::peek() const
{
	if (isEmpty()) return -1;
	int temp = top->value;
	return temp;
}