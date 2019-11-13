#pragma once
#include "Task.h"

class Cluster
{
	int Value;								// ���������� �����������
	int *CPU;								// ����� ��� �����������
public:
	Cluster();
	Cluster(int _v);
	~Cluster();

	int IsFree();							// ���������� ��������� �����������
	bool ExeTask(Task &T);					// ������ ������ �� ����������
	void DecreaseAfterExe();				// �������� ����� ��������� ������ �� ���������� ������
};

