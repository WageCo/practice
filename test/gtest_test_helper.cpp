#include <gtest/gtest.h>
#include "helper.h"

TEST(HelperTests, hello_world_test)
{
    helper::hello_world();
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
