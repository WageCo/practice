#ifndef __MY_HELPER_CPP17_ADD_H__
#define __MY_HELPER_CPP17_ADD_H__

#include <cstddef>
#include <string>
#include <type_traits>

namespace helper {

// 类型检测命名空间
namespace type_traits {
// 字符串类型检测

// 方法一 
// C字符串类型
// template <typename T>
// struct is_c_string : std::false_type {};
// template <>
// struct is_c_string<char*> : std::true_type {};
// template <>
// struct is_c_string<const char*> : std::true_type {};
// template <size_t N>
// struct is_c_string<char[N]> : std::true_type {};
// template <size_t N>
// struct is_c_string<const char[N]> : std::true_type {};

// std::string类型
// template <typename T>
// struct is_std_string : std::false_type {};
// template <>
// struct is_std_string<std::string> : std::true_type {};

// 字符串检测
// template <typename T, typename... Ts>
// constexpr bool is_string_v = is_c_string<T>::value || is_std_string<T>::value;

// 方法二 (C++17折叠表达式)
template <typename T, typename... Ts>
constexpr bool is_any_of_v = (std::is_same_v<T, Ts> || ...);

template <typename T>
constexpr bool is_string_v = is_any_of_v<T, char*, const char*, std::string>;
template <size_t N>
constexpr bool is_string_v<char [N]> = std::true_type::value;
template <size_t N>
constexpr bool is_string_v<const char [N]> = std::true_type::value;

// 字符串检测
template <typename T>
struct is_string : std::bool_constant<is_string_v<T>> {};
}  // namespace type_traits

// 数值相加
template <typename T1, typename T2>
inline auto add(const T1& a, const T2& b) -> typename std::enable_if<
    (std::is_arithmetic<typename std::remove_cv<T1>::type>::value &&
     std::is_arithmetic<typename std::remove_cv<T2>::type>::value),
    decltype(a + b)>::type {
  return a + b;
}

// 字符串拼接
template <typename T1, typename T2>
inline auto add(const T1& a, const T2& b) -> typename std::enable_if<
    (type_traits::is_string<typename std::remove_cv<T1>::type>::value ||
     type_traits::is_string<typename std::remove_cv<T2>::type>::value),
    std::string>::type {
  using namespace type_traits;

  // 将非字符串类型转换为字符串
  if constexpr (is_string<T1>::value && std::is_arithmetic<T2>::value) {
    return std::string(a) + std::to_string(b);
  } else if constexpr (is_string<T2>::value && std::is_arithmetic<T1>::value) {
    return std::to_string(a) + std::string(b);
  } else {
    return std::string(a) + std::string(b);
  }
}

}  // namespace helper

#endif  // __MY_HELPER_CPP17_ADD_H__
