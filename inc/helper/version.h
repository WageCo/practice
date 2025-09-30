#ifndef __MY_HELPER_VERSION_H__
#define __MY_HELPER_VERSION_H__

namespace helper {
namespace version {

constexpr int MAJOR_VERSION = 0;
constexpr int MINOR_VERSION = 1;
inline const int get_major_version() { return MAJOR_VERSION; }
inline const int get_minor_version() { return MINOR_VERSION; }

constexpr int CPP_STANDARD = __cplusplus;
inline const int get_cpp_standard() { return CPP_STANDARD; }

// 若当前支持C++20及以上版本，则启动宏定义, 以下代码块可选
#if __cplusplus >= 202002L
#define __HELPER_IMP_CPP20_OR_LATER__
#endif

// 测试低版本代码时可手动取消宏定义
#undef __HELPER_IMP_CPP20_OR_LATER__

}  // namespace version
}  // namespace helper
#endif  // __MY_HELPER_VERSION_H__