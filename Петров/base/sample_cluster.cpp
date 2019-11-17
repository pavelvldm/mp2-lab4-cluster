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

	cout << "������� ���������� ������: ";
	cin >> vTact;

	cout << "������� ���������� �����������: ";
	cin >> vCPU;

	Cluster DemoCluster(vCPU);

	DemoCluster.RunCluster(vTact);

	system("pause");
	return 0;
}