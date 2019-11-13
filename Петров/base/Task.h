#pragma once

const int MIN_CPU_AMOUNT = 4;
const int MAX_CPU_AMOUNT = 64;

class Task
{
	int ID;							// идентификатор
	int pTask;						// число требуемых процессоров
	int tTask;						// число тактов для выполнения
	int tact;						// такт начала выполнения
public:
	Task();
	Task(int _ID, int p, int t);
	~Task();

	int GetpTask() { return pTask; }
	int GettTask() { return tTask; }
	void SetTact(int n) { tact = n; }

	void tDecrease();
};

