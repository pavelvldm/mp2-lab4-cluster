#include "queue.h"
#include "Queue_Methods.cpp"
#include <gtest.h>

TEST(Queue, can_create_queue)
{
	ASSERT_NO_THROW(Queue<int> testQueue);
}

TEST(Queue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> testQueue(8));
}

TEST(Queue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> testQueue(-8));
}

TEST(Queue, cant_create_too_large_queue)
{
	ASSERT_ANY_THROW(Queue<int> testQueue(MAX_QUEUE_SIZE + 1));
}

TEST(Queue, can_add_last_in_queue)
{
	Queue<int> testQueue(5);
	int testElem = 9;

	ASSERT_NO_THROW(testQueue.AddLast(testElem));
}

TEST(Queue, can_delete_last_in_queue)
{
	Queue<int> testQueue(5);
	int testElem = 9;
	testQueue.AddLast(testElem);

	EXPECT_EQ(testElem, testQueue.DelLast());
}