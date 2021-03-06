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
	Node *top1 = head;
	while (top1)
	{
		str += top1->value + 48;
		top1 = top1->n;
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
	if (isEmpty()) tail = ps;
	else head->p = ps;
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
	if (isEmpty()) throw 1;
	int temp = head->value;
	Node *ps = head->n;
	delete head;
	head = ps;
	if (head) head->p = NULL;
	else tail = NULL;
	siz--;
	return temp;
}

int LinkedDeque::popBack()
{
	if (isEmpty()) throw 1;
	int tp;
	tp = tail->value;
	Node *temp = new Node;
	temp = tail->p;
	delete tail;
	tail = temp;
	if (isEmpty()) head = NULL;
	else tail->n = NULL;
	siz--;
	return tp;
}

int LinkedDeque::peekFront() const
{
	if (isEmpty()) throw 1;
	return head->value;
}

int LinkedDeque::peekBack() const
{
	if (isEmpty()) throw 1;
	return tail->value;
}
