#include "helper.h"
#include <gtest/gtest.h>

TEST(HelperTests, helper_add_test) {
  int a = 1;
  int b = 1;
  int sum = 0;
  sum = helper::add(a, b);
  EXPECT_EQ(sum, 2);
}

TEST(HelperTests, helper_version_test) {
  using namespace helper;
  EXPECT_EQ(version::get_major_version(), version::MAJOR_VERSION);
  EXPECT_EQ(version::get_minor_version(), version::MINOR_VERSION);
}

TEST(HelperTests, helper_cpp_standard_test) {
  using namespace helper;
  EXPECT_EQ(version::get_cpp_standard(), version::CPP_STANDARD);
  EXPECT_EQ(version::get_cpp_standard(), __cplusplus);

  // 输出当前使用的C++标准
  std::cout << "C++ Standard: " << version::get_cpp_standard() << std::endl;
}