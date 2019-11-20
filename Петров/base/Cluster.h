#pragma once
#include "Task.h"

class Cluster
{
	int Value;																					// ���������� �����������
	int *CPU;																					// ����� ��� �����������
public:
	Cluster(const int &_v);
	~Cluster();

	int IsFree();																				// ���������� ��������� �����������
	bool ExeTask(Task &T);																		// ������ ������ �� ����������
	void DecreaseAfterExe();																	// �������� ����� ��������� ������ �� ���������� ������
	void RunCluster(const int &_tact, const int &_vTask, const int &_vTact, const int &_vCPU);
};

