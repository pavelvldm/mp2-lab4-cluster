#include "queue.h"
#include "Task.h"
#include "Cluster.h"

using namespace std;

int main()
{

	int vTact, vCPU;

	cout << "¬ведите количество тактов: ";
	cin >> vTact;

	cout << "¬ведите количество процессоров: ";
	cin >> vCPU;

	Cluster DemoCluster(vCPU);

	DemoCluster.RunCluster(vTact);

	system("pause");
	return 0;
}