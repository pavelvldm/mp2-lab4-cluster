#include "Task.h"
#include "Task_Methods.cpp"
#include <gtest.h>

TEST(Task, can_create_task)
{
	ASSERT_NO_THROW(Task testTask);
}

TEST(Task, can_create_task_with_definitions)
{
	ASSERT_NO_THROW(Task testTask(1001, 5, 2));
}

TEST(Task, cant_create_task_with_negative_CPU_number)
{
	ASSERT_ANY_THROW(Task testTask(1001, -3, 10));
}

TEST(Task, cant_create_task_with_too_large_CPU_number)
{
	ASSERT_ANY_THROW(Task testTask(1001, 90, 10));
}

TEST(Task, cant_create_task_with_negative_tact_number)
{
	ASSERT_ANY_THROW(Task testTask(1001, 6, -1));
}

TEST(Task, can_assign_task)
{
	Task testTask(1001, 4, 5);
	Task checkTask;

	checkTask = testTask;

	EXPECT_EQ(testTask, checkTask);
}

TEST(Task, can_assign_equal_tasks)
{
	Task testTask(1001, 4, 5);
	Task checkTask(1001, 4, 5);

	checkTask = testTask;

	EXPECT_EQ(testTask, checkTask);
}