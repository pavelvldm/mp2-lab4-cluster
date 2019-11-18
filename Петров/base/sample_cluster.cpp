#include "queue.h"
#include "Task.h"
#include "Cluster.h"
#include "Statistics.h"

#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Rus");

	int vTact, vCPU, _vTask, _vTact, _vCPU;

	cout << "Введите количество тактов: ";
	cin >> vTact;

	cout << "Введите количество процессоров на кластере: ";
	cin >> vCPU;

	cout << "Введите максимальное количество новых задач на такте: ";
	cin >> _vTask;

	cout << "Введите максимальное количество тактов для выполнения одной задачи: ";
	cin >> _vTact;

	cout << "Введите максимальное количество процессоров для выполнения одной задачи: ";
	cin >> _vCPU;

	try
	{
		Cluster DemoCluster(vCPU);

		DemoCluster.RunCluster(vTact, _vTask, _vTact, _vCPU);
	}
	catch (int a)
	{
		if (a == 1) cout << "\tОшибка: Недопустимое количество процессоров" << endl;
	}

	system("pause");
	return 0;
}