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

	cout << "������� ���������� ������: ";
	cin >> vTact;

	cout << "������� ���������� ����������� �� ��������: ";
	cin >> vCPU;

	cout << "������� ������������ ���������� ����� ����� �� �����: ";
	cin >> _vTask;

	cout << "������� ������������ ���������� ������ ��� ���������� ����� ������: ";
	cin >> _vTact;

	cout << "������� ������������ ���������� ����������� ��� ���������� ����� ������: ";
	cin >> _vCPU;

	try
	{
		Cluster DemoCluster(vCPU);

		DemoCluster.RunCluster(vTact, _vTask, _vTact, _vCPU);
	}
	catch (int a)
	{
		if (a == 1) cout << "\t������: ������������ ���������� �����������" << endl;
	}

	system("pause");
	return 0;
}