#include <gtest/gtest.h>
#include <iostream>
#include "../../MultiClass.h"

TEST(Multi, NORMAL)
{
	MultiClass multi;
	EXPECT_EQ(16, multi.Multi(5,3,4,2));
	EXPECT_EQ(45, multi.Multi(6,3,7,2));
	EXPECT_EQ(60, multi.Multi(7,3,8,2));
}
