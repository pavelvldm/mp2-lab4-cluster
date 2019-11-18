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
		throw 1;
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

void Cluster::RunCluster(const int &_tact, const int &_vTask, const int &_vTact, const int &_vCPU)
{
	srand(time(NULL));

	try
	{
		if ((_tact < 1) || (_vTask < 1) || (_vTact < 1) || (_vCPU < 1))
			throw 4;

		if (_tact * _vTask > MAX_QUEUE_SIZE)
			throw 2;

		if (_vCPU > Value)
			throw 3;

		Queue<Task> ForTask(_tact * _vTask);
		std::vector<Task> ExTask;

		Statistics ClusterStat;

		for (int i = 0; i < _tact; i++)
		{
			// на каждом такте приходят задачи от 1 до _vTask
			int vTask = rand() % _vTask + 1;								// количество задач
			ClusterStat.AddAppeared(vTask);
			ClusterStat.SetMax(vTask);

			// создаём задачи и записываем в очередь
			for (int j = 0; j < vTask; j++)
			{
				int IDtmp = 1000 + i * 10 + j;
				int Ptmp = rand() % _vCPU + 1;
				int Ttmp = rand() % _vTact + 1;

				Task tmp(IDtmp, Ptmp, Ttmp);
				ForTask.AddLast(tmp);
			}

			int k = 0;
			while ((k < vTask) && (IsFree()))
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
	catch (int a)
	{
		if (a == 2) std::cout << "\tОшибка: Недопустимый размер очереди" << std::endl;
		if (a == 3) std::cout << "\tОшибка: Недопустимое максимально количество процессоров для задачи" << std::endl;
		if (a == 4) std::cout << "\tОшибка: Неверные значения параметров" << std::endl;
	}
}