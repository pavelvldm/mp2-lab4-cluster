#include "queue.h"

template <typename T>
void Queue<T>::AddLast(const T& elem)
{
	if (IsFull())
		throw std::exception("No space");

	if (!IsFull())
	{
		End++;
		End = End % Size;
		Qe[End] = elem;
		Amount++;
	}
}

template <typename T>
T Queue<T>::DelFirst()
{
	if (IsEmpty())
		throw std::exception("No elements");

	int Current = Start;

	Amount--;
	Start = (Start + 1) % Size;

	return Qe[Current];
}