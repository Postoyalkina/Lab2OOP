// OOPlab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include <iostream>

using namespace std;

int main()
{
	ArrayList *q = new ArrayList(6);
	cout << q->toString() << endl;
	q->pop();
	q->push(7);
	cout << q->toString() << endl;
	q->insertAt(1, 8);
	cout << q->toString() << endl;
	q->removeAt(0);
	cout << q->toString() << endl;
	system("pause");
    return 0;
}

