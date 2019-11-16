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

	cout << "¬ведите количество тактов: ";
	cin >> vTact;

	cout << "¬ведите количество процессоров: ";
	cin >> vCPU;

	Cluster DemoCluster(vCPU);

	DemoCluster.RunCluster(vTact, 2, 3);

	system("pause");
	return 0;
}