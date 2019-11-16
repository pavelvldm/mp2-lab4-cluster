#pragma once

class Statistics
{
	int Appeared;					// ����� ����������� �����
	int InQueue;					// ����� ����� � �������
	int Completed;					// ����� ����������� �����
	double ACL;						// ������� �������� ��������
public:

	Statistics()
	{
		Appeared = 0;
		InQueue = 0;
		Completed = 0;
		ACL = 0;
	}

	void AddAppeared(const int &_a)
	{
		Appeared += _a;
	}

	void SetInQueue(const int &_q)
	{
		InQueue = _q;
	}

	void AddCompleted(const int &_c)
	{
		Completed += _c;
	}

	void PrintStat()
	{
		std::cout << std::endl << "\t������ ���������. ����������: " << std::endl;
		std::cout << "����� ����������� �����: " << Appeared << std::endl;
		std::cout << "����� ������������� �����: " << Completed << std::endl;
		std::cout << "����� ����� � �������: " << InQueue << std::endl;
		std::cout << "������� �������� ��������: " << ACL << std::endl;
	}
};

