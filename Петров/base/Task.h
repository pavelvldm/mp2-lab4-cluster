#pragma once

const int MIN_CPU_AMOUNT = 4;
const int MAX_CPU_AMOUNT = 64;

class Task
{
	int ID;							// идентификатор
	int pTask;						// число требуемых процессоров
	int tTask;						// число тактов для выполнения
public:
	Task();
	Task(const int &_ID, const int &_p, const int &_t);
	~Task();

	int GetpTask() { return pTask; }
	int GettTask() { return tTask; }

	Task& operator=(const Task &tmp)
	{
		if (this != &tmp)
		{
			ID = tmp.ID;
			pTask = tmp.pTask;
			tTask = tmp.tTask;
		}
		
		return *this;
	}

	bool operator==(const Task &tmp) const
	{
		if ((ID == tmp.ID) && (pTask == tmp.pTask) && (tTask == tmp.tTask))
			return true;
		else
			return false;
	}

	void DecreaseAfterExe();
};

