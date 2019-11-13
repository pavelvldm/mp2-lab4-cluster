#include "Cluster.h"
#include <iostream>

Cluster::Cluster()
{
	Value = 0;
	CPU = nullptr;
}

Cluster::Cluster(int _v)
{
	if ((_v < MIN_CPU_AMOUNT) || (_v > MAX_CPU_AMOUNT))
		throw std::exception("Wrong value");
	Value = _v;
	CPU = new int[Value];

	for (int i = 0; i < Value; i++)
		CPU[i] = 0;
}

Cluster::~Cluster()
{
	delete[] CPU;
}

int Cluster::IsFree()
{
	int FreeCPU = 0;

	for (int i = 0; i < Value; i++)
		if (CPU[i] == 0)
			FreeCPU++;

	return FreeCPU;
}

bool Cluster::ExeTask(Task &task)
{
	if (IsFree() < task.GetpTask())
		return false;
	else
	{
		for (int i = 0; i < Value; i++)
			if (CPU[i] == 0)
				CPU[i] = task.GettTask();
		return true;
	}
}

void Cluster::DecreaseAfterExe()
{
	for (int i = 0; i < Value; i++)
		if (CPU[i]) 
			CPU[i]--;
}