#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

const int MAX_QUEUE_SIZE = 100;

template <typename T>
class Queue
{
	T* Qe;													// очередь
	int Start;												// первый в очереди
	int End;												// последний в очереди
	int Amount;												// количество элементов в очереди
public:
	Queue()
	{
		Start = 0;
		End = -1;
		Amount = 0;
		Qe = new T[MAX_QUEUE_SIZE];
	}

	Queue(int Size)
	{
		if ((Size < 1) || (Size > MAX_QUEUE_SIZE))
			throw std::exception("Wrong size");

		Start = 0;
		End = -1;
		Amount = 0;
		Qe = new T[Size];
	}

	~Queue()
	{
		delete[] Qe;
	}

	void AddLast(T& elem);									// вставить в конец очереди
	T DelLast();											// удалить последний
	T DelFirst();											// удалить первый

	bool IsFull()											// проверка очереди на полноту
	{
		if (!Amount)
			return false;

		if (Amount % MAX_QUEUE_SIZE)
			return false;
		else
			return true;
	}
};

#endif