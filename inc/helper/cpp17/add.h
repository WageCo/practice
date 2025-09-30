#ifndef __MY_HELPER_CPP17_ADD_H__
#define __MY_HELPER_CPP17_ADD_H__

#include <string>
#include <type_traits>

namespace helper {

// 删除指针类型的支持, 以避免潜在的悬空指针问题, 并确保类型安全
// 通过SFINAE实现
template <typename T1, typename T2>
inline auto add(const T1& a, const T2& b) ->
    typename std::enable_if<!std::is_pointer<T1>::value &&
                                !std::is_pointer<T2>::value,
                            decltype(a + b)>::type {
  return a + b;
}

// 针对char数组 重载版本
template <size_t N1, size_t N2>
inline std::string add(const char (&a)[N1], const char (&b)[N2]) {
  return std::string(a) + b;
}

// 支持 const char* 重载版本
inline std::string add(const char* a, const char* b) {
  return std::string(a) + b;
}

}  // namespace helper

#endif  // __MY_HELPER_CPP17_ADD_H__
