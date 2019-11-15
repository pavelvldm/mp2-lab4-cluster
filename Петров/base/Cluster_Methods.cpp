#include "Cluster.h"
#include "queue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

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

void Cluster::RunCluster(int _tact, int maxP, int maxT, int maxTask)
{
	if ((_tact < maxT) || (maxP > Value))
		throw std::exception("Wrong parameters");

	srand(time(NULL));

	Queue<Task> ForTask(MAX_QUEUE_SIZE);

	for (int i = 0; i < _tact; i++)
	{
		// на каждом такте приходят задачи
		int vTask = rand() % maxTask + 1;								// количество задач

		// создаём задачи и записываем в очередь
		for (int j = 0; j < vTask; j++)
		{
			int IDtmp = 1000 + i * 10 + j;
			int Ptmp = rand() % maxP + 1;
			int Ttmp = rand() % maxT + 1;

			Task tmp(IDtmp, Ptmp, Ttmp);
			ForTask.AddLast(tmp);
		}

		int k = 0;
		while ((IsFree()) || (k <= vTask))
		{
			Task tmp;
			tmp = ForTask.DelFirst();

			// если задача не пошла на кластер, то возвращаем в очередь
			if (!ExeTask(tmp))
				ForTask.AddLast(tmp);

			k++;
		}

		DecreaseAfterExe();
	}
}