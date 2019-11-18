#include "queue.h"
#include "Task.h"
#include "Cluster.h"
#include "Statistics.h"

#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Rus");

	int vTact, vCPU;

	cout << "Введите количество тактов: ";
	cin >> vTact;

	cout << "Введите количество процессоров: ";
	cin >> vCPU;

	try
	{
		Cluster DemoCluster(vCPU);

		DemoCluster.RunCluster(vTact);
	}
	catch (int a)
	{
		if (a == 1) cout << "Ошибка: Недопустимое количество процессоров" << endl;
	}

	system("pause");
	return 0;
}