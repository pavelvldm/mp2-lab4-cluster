#include "Cluster.h"
#include "Cluster_Methods.cpp"
#include <gtest.h>

TEST(Cluster, can_create_cluster_with_value)
{
	ASSERT_NO_THROW(Cluster testCluster(16));
}

TEST(Cluster, cant_create_cluster_with_negative_value)
{
	ASSERT_ANY_THROW(Cluster testCluster(-9));
}

TEST(Cluster, cant_create_cluster_with_value_less_than_4)
{
	ASSERT_ANY_THROW(Cluster testCluster(2));
}

TEST(Cluster, cant_create_too_large_cluster)
{
	ASSERT_ANY_THROW(Cluster testCluster(128));
}

TEST(Cluster, created_cluster_is_free)
{
	Cluster testCluster(4);

	EXPECT_EQ(4, testCluster.IsFree());
}

TEST(Cluster, can_execute_correct_task_on_cluster)
{
	Cluster testCluster(4);
	Task testTask(1000, 2, 1);

	EXPECT_EQ(true, testCluster.ExeTask(testTask));
}

TEST(Cluster, cant_execute_incorrect_task_on_cluster)
{
	Cluster testCluster(4);
	Task testTask(1000, 16, 1);

	EXPECT_EQ(false, testCluster.ExeTask(testTask));
}

TEST(Cluster, cant_execute_correct_task_when_cluster_is_not_free)
{
	Cluster testCluster(4);
	Task Task1(1000, 2, 5);
	Task Task2(1001, 2, 5);
	Task Task3(1002, 2, 5);
	Task Task4(1003, 2, 5);

	Task testTask(1004, 2, 5);

	testCluster.ExeTask(Task1);
	testCluster.ExeTask(Task2);
	testCluster.ExeTask(Task3);
	testCluster.ExeTask(Task4);

	EXPECT_EQ(false, testCluster.ExeTask(testTask));
}