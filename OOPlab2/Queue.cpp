#include "stdafx.h"
#include "Queue.h"


Queue::Queue(int value)
{
	head = new(Node); //Выделяем память под элемент
	tail = head; // При создании очереди хвост и голова являются одним и тем же элементом
	head->value = value; // Записываем значение
	head->p = 0; // Адрес ноль, так как следующего элемента пока нет
	siz = 1; // После выделения памяти и заполянения полей структуры очередь стала иметь размер 1

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
	siz++;// Кол-во элементов очереди увеличивается
	Node *temp = new Node; // Выделяем память под новый хвост очереди
	temp->p = 0; // Записываем в поле адреса нового хвоста ноль, так как за ничего нету
	temp->value = value; //Заполняем поле значения нового хвоста
	tail->p = temp; // Записываем в поле адреса старого хвоста адрес нового хвоста
	tail = temp; //Записываем в указель хвоста адрес действительного хвоста

	return true;
}

int Queue::pop()
{
	if (isEmpty())
	{
		return -1;
	}

	Node *temp = head; // записываем адрес головы
	head = head->p; // изменяем адрес головы
	delete temp;  // удаляем старую голову
	siz--; // уменьшаем размер
	return 1;
}

bool Queue::isEmpty() const
{
	if (tail == nullptr) return true;
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
	//reverse(str.begin(), str.end());
	return str;
}

int Queue::peek() const
{
	if(isEmpty()) return -1;
	int temp = head->value;
	return temp;
}