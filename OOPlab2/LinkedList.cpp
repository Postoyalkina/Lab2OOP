#include "stdafx.h"
#include "LinkedList.h"


LinkedList::LinkedList()
{
	head = tail = NULL;
	siz = 0;
}


LinkedList::~LinkedList()
{
	while (head)
	{
		Node *ps = head;
		head = head->p;
		delete ps;
	}
}

LinkedList::LinkedList(int value)
{
	Node *temp = new Node;
	temp->value = value;
	temp->p = temp->n = NULL;
	head = tail = temp;
	siz = 1;
}
int LinkedList::pop()
{
	if (isEmpty()) throw 1;
	int tp;
	tp = tail->value;
	Node *temp = new Node;
	temp = tail->p;
	delete tail;
	tail = temp;
	if (isEmpty()) tail = head = 0;
	else tail->n = NULL;
	siz--;
	return tp;
}

bool LinkedList::push(int value)
{
	Node *temp = new Node;
	temp->value = value;
	temp->n = NULL;
	temp->p = tail;
	if (isEmpty()) head = tail;
	else tail->n = temp;
	tail = temp;
	siz++;
	return true;
}

bool LinkedList::insertAt(int index, int value)
{
	if (index > siz) return false;
	Node *temp = new Node;
	temp->value = value;
	int tp = value;
	temp->n = head;
	temp->p = NULL;
	if (isEmpty()) tail = temp;
	else head->p = temp;
	siz++;
	head = temp;
	for (int i = 0; i < index; i++)
	{
		tp = get(i+1);
		set(i, get(i));
		set(i-1, tp);
	}
	return true;
}

int LinkedList::removeAt(int index)
{
	if (index > siz) throw 2;
	int tpH = head->value;
	int tp = 0;
	Node *temp = new Node;
	temp = head->n;
	delete head;
	head = temp;
	if (head) head->p = NULL;
	else tail = NULL;
	for (int i = 0; i < index-1; i++)
	{
		tp = get(i);
		set(i-1, tpH);
		tpH = tp;
	}
	siz--;
	return 0;
}

int LinkedList::peek() const
{
	if (isEmpty()) throw 1;
	return head->value;
}

int LinkedList::size() const
{
	return siz;
}

bool LinkedList::isEmpty() const
{
	if (head == nullptr) return true;
	else return false;
}

string LinkedList::toString() const
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

int LinkedList::get(int index) const
{
	if (index >= siz) throw 2;
	Node *temp = new Node;
	temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->n;
	}
	return temp->value;
}

void LinkedList::set(int index, int value)
{
	if (index >= siz) throw 2;
	Node *temp = new Node;
	temp = head;
	for (int i = 0; i <= index; i++)
	{
		temp = temp->n;
	}
	temp->value = value;
}
