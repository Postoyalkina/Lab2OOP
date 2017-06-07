#include "stdafx.h"
#include "Queue.h"


Queue::Queue()
{
	head = tail = NULL;
	siz = 0;
}

Queue::Queue(int value)
{
	head = new(Node);
	tail = head;
	head->value = value;
	head->p = 0; 
	siz = 1; 

}


Queue::~Queue()
{
	while (head)
	{
		Node *ps = head;
		head = head->p;
		delete ps;
	}
}

bool Queue::push(int value)
{
	Node *temp = new Node;
	temp->p = 0;
	temp->value = value;
	if (isEmpty()) head = temp;
	else tail->p = temp; // Записываем в поле адреса старого хвоста адрес нового хвоста
	tail = temp; //Записываем в указель хвоста адрес действительного хвоста

	siz++;
	return true;
}

int Queue::pop()
{
	if (isEmpty())	throw 1;
	int temp = head->value;
	Node *tmp = head; // записываем адрес головы
	head = head->p; // изменяем адрес головы
	delete tmp;  // удаляем старую голову
	siz--; // уменьшаем размер
	return temp;
}

int Queue::peek() const
{
	if (isEmpty()) throw 1;
	return head->value;
}

bool Queue::isEmpty() const
{
	if (siz == 0) return true;
	else return false;
}

int Queue::size() const
{
	return siz;
}

string Queue::toString() const
{
	int i = 0;
	string str = "";
	Node *top1 = head;
	while (top1)
	{
		str += top1->value + 48;
		top1 = top1->p;
		i++;
	}
	return str;
}