#pragma once
#include "Task.h"

class Cluster
{
	int Value;								// количество процессоров
	int *CPU;								// флаги для процессоров
public:
	Cluster();
	Cluster(int _v);
	~Cluster();

	int IsFree();							// количество свободных процессоров
	bool ExeTask(Task &T);					// ставим задачу на исполнение
	void DecreaseAfterExe();				// понижаем число требуемых тактов на исполнение задачи
};

