#include "helper.h"
#include <gtest/gtest.h>

TEST(HelperTests, helper_add_test) {
  using namespace helper;
  EXPECT_EQ(add(1, 2), 3);
  EXPECT_EQ(add(1.5, 2.5), 4.0);
  EXPECT_EQ(add(std::string("Hello, "), std::string("World!")),
            std::string("Hello, World!"));
  EXPECT_EQ(add("Hello, ", "World!"), std::string("Hello, World!"));

  const char * s1 = "Good ";
  const char * s2 = "Morning!";
  EXPECT_EQ(add(s1, s2), std::string("Good Morning!"));

  EXPECT_EQ(add(1, 2.5), 3.5);
  EXPECT_EQ(add(2.5, 1), 3.5);

  int a = 10;
  int b = 20;
  EXPECT_EQ(add(a, b), 30);
  EXPECT_EQ(add(a, 2.5), 12.5);
  EXPECT_EQ(add(2.5, b), 22.5);

  // 以下代码应编译错误, 因为不支持指针类型
  // int* p1 = &a;
  // int* p2 = &b;
  // EXPECT_EQ(add(p1, p2), nullptr);
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