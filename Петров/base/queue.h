#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

const int MAX_QUEUE_SIZE = 100;

template <typename T>
class Queue
{
	T* Qe;													// �������
	int Start;												// ������ � �������
	int End;												// ��������� � �������
	int Amount;												// ���������� ��������� � �������
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

	void AddLast(T& elem);									// �������� � ����� �������
	T DelLast();											// ������� ���������
	T DelFirst();											// ������� ������

	bool IsFull()											// �������� ������� �� �������
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