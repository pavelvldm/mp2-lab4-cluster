#include "queue.h"
#include "Task.h"
#include "Cluster.h"

using namespace std;

int main()
{

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