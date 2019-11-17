#ifndef __QUEUE_H__
#define __QUEUE_H__

const int MAX_QUEUE_SIZE = 10000;

template <typename T>
class Queue
{
	T* Qe;													// �������
	int Start;												// ������ � �������
	int End;												// ��������� � �������
	int Amount;												// ���������� ��������� � �������
	int Size;												// ������ �������
public:
	Queue()
	{
		Start = 0;
		End = -1;
		Amount = 0;
		Size = MAX_QUEUE_SIZE;
		Qe = new T[Size];
	}

	Queue(int sz)
	{
		if ((sz < 1) || (sz > MAX_QUEUE_SIZE))
			throw std::exception("Wrong size");

		Start = 0;
		End = -1;
		Amount = 0;
		Size = sz;
		Qe = new T[Size];
	}

	~Queue()
	{
		delete[] Qe;
	}

	void AddLast(const T& elem);									// �������� � ����� �������
	T DelFirst();													// ������� ������

	int GetSize() { return Size; }
	int GetAmount() { return Amount; }
	int GetStart() { return Start; }
	int GetEnd() { return End; }

	bool IsFull()													// �������� ������� �� �������
	{
		if (Amount == Size)
			return true;
		else
			return false;
	}

	bool IsEmpty()
	{
		if (Amount > 0)
			return false;
		else
			return true;
	}
};

#endif