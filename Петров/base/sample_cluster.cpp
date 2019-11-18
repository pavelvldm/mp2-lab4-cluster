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

	try
	{
		Cluster DemoCluster(vCPU);

		DemoCluster.RunCluster(vTact);
	}
	catch (int a)
	{
		if (a == 1) cout << "������: ������������ ���������� �����������" << endl;
	}

	system("pause");
	return 0;
}