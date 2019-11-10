#include "queue.h"

template <typename T>
void Queue<T>::AddLast(T& elem)
{
	if (!IsFull())
	{
		End++;
		End = End % MAX_QUEUE_SIZE;
		Qe[End] = elem;
		Amount++;
	}

	if (IsFull())
		throw std::exception("No space");
}

template <typename T>
T Queue<T>::DelLast()
{
	if (Amount < 1)
		throw std::exception("No elements");

	int Current = End;

	Amount--;
	End = (End - 1) % MAX_QUEUE_SIZE;

	return Qe[Current];
}

template <typename T>
T Queue<T>::DelFirst()
{
	if (Amount < 1)
		throw std::exception("No elements");

	int Current = Start;

	Amount--;
	Start = (Start + 1) % MAX_QUEUE_SIZE;

	return Qe[Current];
}