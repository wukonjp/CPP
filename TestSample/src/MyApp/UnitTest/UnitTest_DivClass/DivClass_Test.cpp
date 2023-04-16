#include <gtest/gtest.h>
#include <iostream>
#include "../../DivClass.h"

TEST(Div, NORMAL)
{
	DivClass div;
	EXPECT_EQ(0, div.Div(5,3,4,2));
	EXPECT_EQ(0, div.Div(6,3,7,2));
	EXPECT_EQ(0, div.Div(7,3,8,2));
}
