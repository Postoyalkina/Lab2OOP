#include "stdafx.h"
#include "LinkedDeque.h"


LinkedDeque::LinkedDeque()
{
	head = tail = NULL;
	siz = 0;
}

LinkedDeque::LinkedDeque(int value)
{
	Node *temp = new Node;
	temp->value = value;
	temp->p = temp->n = NULL;
	head = tail = temp;
	siz = 1;
}

LinkedDeque::~LinkedDeque()
{
	while (head)
	{
		Node *ps = head;
		head = head->p;
		delete ps;
	}
}

int LinkedDeque::size() const
{
	return siz;
}

bool LinkedDeque::isEmpty() const
{
	if (head == nullptr) return true;
	else return false;
}

string LinkedDeque::toString() const
{
	int i = 0;
	string str = "";
	Node *top1 = tail;
	while (top1)
	{
		str += top1->value + 48;
		top1 = top1->p;
		i++;
	}
	reverse(str.begin(), str.end());
	return str;
}

bool LinkedDeque::pushFront(int value)
{
	siz++;
	Node *ps = new Node;
	ps->value = value;
	ps->p = NULL;
	ps->n = head;
	head = ps;
	return true;
}

bool LinkedDeque::pushBack(int value)
{
	siz++;
	Node *temp = new Node;
	temp->value = value;
	temp->n = NULL;
	temp->p = tail;
	if (isEmpty()) head = tail;
	else tail->n = temp;
	tail = temp;
	return true;
}

int LinkedDeque::popFront()
{
	siz--;
	if (isEmpty()) return -1;
	int temp = head->value;
	Node *ps = head->n;
	delete head;
	head = ps;
	if (head) head->p = NULL;
	else tail = NULL;
	return temp;
}

int LinkedDeque::popBack()
{
	int tp;
	siz--;
	tp = tail->value;
	Node *temp = new Node;
	temp = tail->p;
	delete tail;
	tail = temp;
	if (isEmpty()) tail = head = 0;
	else tail->n = NULL;
	return tp;
}

int LinkedDeque::peekFront() const
{
	if (isEmpty()) return -1;
	int temp = head->value;
	return temp;
}

int LinkedDeque::peekBack() const
{
	if (isEmpty()) return -1;
	int temp = tail->value;
	return temp;
}
