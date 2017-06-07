// OOPlab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "StaticArray.h"
#include "StaticDeque.h"
#include "LinkedDeque.h"

#include <iostream>

using namespace std;

int main()
{
	Container *arr[3] = { new Stack(), new StaticArray(5,5), new LinkedDeque()};
	PushPopContainer *a;
	Deque *d;
	IndexedContainer *c;
	for (int i = 0; i < 3; i++)
	{
		if (a = dynamic_cast<PushPopContainer*>(arr[i]))
		{
			for (int j = 1; j < 5; j++)
				a->push(j);
			cout << arr[i]->toString() << endl;
		}

		if (a = dynamic_cast<PushPopContainer*>(arr[i]))
		{
			while(!(a->isEmpty()))
				a->pop();
			cout << arr[i]->toString() << endl;
		}

		if (c = dynamic_cast<IndexedContainer*>(arr[i]))
		{
			cout << arr[i]->toString() << endl;
			for (int j = 1; j < 5; j++)
				c->set(j, j);
			cout << arr[i]->toString() << endl;
		}

		if (d = dynamic_cast<Deque*>(arr[i]))
		{
			for (int j = 1; j < 5; j++)
			{
				d->pushFront(j);
				d->pushBack(j+5);

			}
			cout << arr[i]->toString() << endl;
		}

		if (d = dynamic_cast<Deque*>(arr[i]))
		{

			while (!(d->isEmpty()))
			{
				d->popFront();
			}
			cout << arr[i]->toString() << endl;
		}
	}
	
	system("pause");
}

