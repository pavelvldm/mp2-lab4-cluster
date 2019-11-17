#include "Task.h"
#include <iostream>

Task::Task()
{
	ID = 0;
	pTask = 0;
	tTask = 0;
}

Task::Task(int _ID, int _p, int _t)
{
	if ((_p < 1) || (_p > MAX_CPU_AMOUNT))
		throw std::exception("Wrong CPU number");

	if (_t < 1)
		throw std::exception("Wrong tact number");

	ID = _ID;
	pTask = _p;
	tTask = _t;
}


Task::~Task()
{
	ID = 0;
	pTask = 0;
	tTask = 0;
}

void Task::DecreaseAfterExe()
{
	if (tTask > 0)
		tTask--;
}
