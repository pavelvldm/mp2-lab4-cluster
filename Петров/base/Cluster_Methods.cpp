#include "Cluster.h"
#include "queue.h"
#include "Statistics.h"
#include "Task.h"
#include <vector>

#include "Queue_Methods.cpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

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
		int j = task.GetpTask();
		int i = 0;
		while ((i < Value) && (j > 0))
		{
			if (CPU[i] == 0)
			{
				CPU[i] = task.GettTask();
				j--;
			}

			i++;
		}

		return true;
	}
}

void Cluster::DecreaseAfterExe()
{
	for (int i = 0; i < Value; i++)
		if (CPU[i]) 
			CPU[i]--;
}

void Cluster::RunCluster(const int &_tact)
{
	srand(time(NULL));

	try
	{
		Queue<Task> ForTask(_tact * 5);
		std::vector<Task> ExTask;

		Statistics ClusterStat;

		for (int i = 0; i < _tact; i++)
		{
			// на каждом такте приходят задачи от 1 до 5
			int vTask = rand() % 5 + 1;								// количество задач
			ClusterStat.AddAppeared(vTask);
			ClusterStat.SetMax(vTask);

			// создаём задачи и записываем в очередь
			for (int j = 0; j < vTask; j++)
			{
				int IDtmp = 1000 + i * 10 + j;
				int Ptmp = rand() % Value + 1;
				int Ttmp = rand() % _tact + 1;

				Task tmp(IDtmp, Ptmp, Ttmp);
				ForTask.AddLast(tmp);
			}

			int k = 0;
			while ((IsFree()) && (k <= vTask))
			{
				Task tmp;
				tmp = ForTask.DelFirst();

				// если задача не пошла на кластер, то возвращаем в очередь
				if (!ExeTask(tmp))
					ForTask.AddLast(tmp);
				else
					ExTask.push_back(tmp);

				k++;
			}

			for (int m = 0; m < ExTask.size(); m++)
				ExTask[m].DecreaseAfterExe();

			ClusterStat.SetInQueue(ForTask.GetAmount());
			DecreaseAfterExe();
		}

		int CpltTasks = 0;

		for (int i = 0; i < ExTask.size(); i++)
			if (ExTask[i].GettTask() == 0)
				CpltTasks++;

		ClusterStat.AddCompleted(CpltTasks);
		ClusterStat.CountACL(_tact);
		ClusterStat.PrintStat();
	}
	catch (std::exception &e)
	{
		std::cout << "Ошибка: Слишком большой размер очереди" << std::endl;
	}
}