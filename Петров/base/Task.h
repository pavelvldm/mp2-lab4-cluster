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
	Task(int _ID, int p, int t);
	~Task();

	void tDecrease();
};

