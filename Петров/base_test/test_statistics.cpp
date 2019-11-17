#include "Statistics.h"
#include <gtest.h>

TEST(Statistics, can_create_statistics)
{
	ASSERT_NO_THROW(Statistics testStat);
}

TEST(Statistics, can_add_appeared)
{
	Statistics testStat;

	ASSERT_NO_THROW(testStat.AddAppeared(5));
}

TEST(Statistics, cant_add_appeared_when_negative)
{
	Statistics testStat;

	ASSERT_ANY_THROW(testStat.AddAppeared(-7));
}

TEST(Statistics, can_set_InQueue)
{
	Statistics testStat;

	ASSERT_NO_THROW(testStat.SetInQueue(5));
}

TEST(Statistics, cant_set_InQueue_when_negative)
{
	Statistics testStat;

	ASSERT_ANY_THROW(testStat.SetInQueue(-7));
}

TEST(Statistics, can_add_completed)
{
	Statistics testStat;

	ASSERT_NO_THROW(testStat.AddCompleted(5));
}

TEST(Statistics, cant_add_completed_when_negative)
{
	Statistics testStat;

	ASSERT_ANY_THROW(testStat.AddCompleted(-7));
}

TEST(Statistics, can_set_max)
{
	Statistics testStat;

	ASSERT_NO_THROW(testStat.SetMax(5));
}

TEST(Statistics, cant_set_max_when_negative)
{
	Statistics testStat;

	ASSERT_ANY_THROW(testStat.SetMax(-7));
}

TEST(Statistics, can_count_ACL)
{
	Statistics testStat;
	testStat.SetMax(5);
	testStat.AddAppeared(10);

	ASSERT_NO_THROW(testStat.CountACL(2));
}

TEST(Statistics, cant_count_ACL_when_negative_parametr)
{
	Statistics testStat;
	testStat.SetMax(5);
	testStat.AddAppeared(10);

	ASSERT_ANY_THROW(testStat.CountACL(-100));
}

TEST(Statistics, cant_count_ACL_when_maxTast_equals_to_zero)
{
	Statistics testStat;
	testStat.AddAppeared(10);

	ASSERT_ANY_THROW(testStat.CountACL(5));
}