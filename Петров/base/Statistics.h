#pragma once
#include <iostream>

class Statistics
{
	int Appeared;					// число появившихся задач
	int InQueue;					// число задач в очереди
	int Completed;					// число завершённых задач
	int NotCompleted;				// число незавершённых задач на кластере
	int MAX_Task;					// максимальное количество пришедших задач
	double ACL;						// средняя загрузка кластера
public:
	Statistics() : Appeared(0), InQueue(0), Completed(0), NotCompleted(0), ACL(0) {}

	void AddAppeared(const int &_a)
	{
		if (_a < 0)
			throw std::exception("Negative Value");

		Appeared += _a;
	}

	void SetInQueue(const int &_q)
	{
		if (_q < 0)
			throw std::exception("Negative Value");

		InQueue = _q;
	}

	void AddCompleted(const int &_c)
	{
		if (_c < 0)
			throw std::exception("Negative Value");

		Completed += _c;
	}

	void AddNotCompleted()
	{
		NotCompleted++;
	}

	void SetMax(const int &_max)
	{
		if (_max < 0)
			throw std::exception("Negative Value");

		if (MAX_Task < _max)
			MAX_Task = _max;
	}

	void CountACL(const int &_t)
	{
		if ((_t < 1) || (MAX_Task < 1))
			throw std::exception("Wrong Value");

		ACL = (0.1 * Appeared / MAX_Task / _t) * 1000;
	}

	void PrintStat()
	{
		std::cout << std::endl << "\tРабота кластера завершена. Статистика: " << std::endl;
		std::cout << "Число появившихся задач: " << Appeared << std::endl;
		std::cout << "Число выполнившихся задач: " << Completed << std::endl;
		std::cout << "Число невыполнившихся задач: " << NotCompleted << std::endl;
		std::cout << "Число задач в очереди: " << InQueue << std::endl;
		std::cout << "Средняя загрузка кластера: " << ACL <<  "%\n\n";
	}
};

