#pragma once

class Statistics
{
	int Appeared;					// число появившихся задач
	int InQueue;					// число задач в очереди
	int Completed;					// число завершённых задач
	double ACL;						// средняя загрузка кластера
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
		std::cout << std::endl << "\tРабота завершена. Статистика: " << std::endl;
		std::cout << "Число появившихся задач: " << Appeared << std::endl;
		std::cout << "Число выполнившихся задач: " << Completed << std::endl;
		std::cout << "Число задач в очереди: " << InQueue << std::endl;
		std::cout << "Средняя загрузка кластера: " << ACL << std::endl;
	}
};

