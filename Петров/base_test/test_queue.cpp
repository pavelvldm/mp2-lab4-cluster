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

TEST(Queue, queue_is_really_empty)
{
	Queue<int> testQueue(5);

	EXPECT_EQ(true, testQueue.IsEmpty());
}

TEST(Queue, can_add_last_in_queue)
{
	Queue<int> testQueue(5);
	int testElem = 9;

	ASSERT_NO_THROW(testQueue.AddLast(testElem));
}

TEST(Queue, queue_is_really_full)
{
	Queue<int> testQueue(2);
	int testElem = 9;

	testQueue.AddLast(testElem);
	testQueue.AddLast(testElem);

	EXPECT_EQ(true, testQueue.IsFull());
}

TEST(Queue, cant_add_last_when_queue_is_full)
{
	Queue<int> testQueue(3);
	int testElem = 9;

	testQueue.AddLast(testElem);
	testQueue.AddLast(testElem);
	testQueue.AddLast(testElem);

	ASSERT_ANY_THROW(testQueue.AddLast(testElem));
}

TEST(Queue, can_delete_first_in_queue)
{
	Queue<int> testQueue(5);
	int testElem = 9;
	testQueue.AddLast(testElem);

	EXPECT_EQ(testElem, testQueue.DelFirst());
}

TEST(Queue, cant_delete_when_queue_is_empty)
{
	Queue<int> testQueue(5);

	ASSERT_ANY_THROW(testQueue.DelFirst());
}

TEST(Queue, end_less_than_start)
{
	Queue<int> testQueue(3);
	int testElem = 9;

	testQueue.AddLast(testElem);
	testQueue.AddLast(testElem);
	testQueue.AddLast(testElem);

	testQueue.DelFirst();
	testQueue.DelFirst();

	testQueue.AddLast(testElem);

	EXPECT_EQ(true, testQueue.GetEnd() < testQueue.GetStart());
}