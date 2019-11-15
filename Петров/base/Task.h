#pragma once

const int MIN_CPU_AMOUNT = 4;
const int MAX_CPU_AMOUNT = 64;

class Task
{
	int ID;							// �������������
	int pTask;						// ����� ��������� �����������
	int tTask;						// ����� ������ ��� ����������
	int tact;						// ���� ������ ����������
public:
	Task();
	Task(const int _ID, const int p, const int t);
	~Task();

	int GetpTask() { return pTask; }
	int GettTask() { return tTask; }
	void SetTact(int n) { tact = n; }

	Task& operator=(const Task &tmp)
	{
		if (this != &tmp)
		{
			ID = tmp.ID;
			pTask = tmp.pTask;
			tTask = tmp.tTask;
			tact = tmp.tact;
		}
		
		return *this;
	}

	void tDecrease();
};

