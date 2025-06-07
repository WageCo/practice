#include <gtest/gtest.h>
#include "helper.h"

TEST(HelperTests, helper_add_test)
{
    int a = 1;
    int b = 1;
    int sum = 0;
    sum = helper::add(a, b);
    EXPECT_EQ(sum, 2);
}
