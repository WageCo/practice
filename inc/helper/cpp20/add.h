#ifndef __MY_HELPER_CPP20_ADD_H__
#define __MY_HELPER_CPP20_ADD_H__

#include <string>
#include <type_traits>

namespace helper {

// 通过concepts实现
template <typename T1, typename T2>
  requires(std::is_arithmetic<T1>::value && std::is_arithmetic<T2>::value)
inline auto add(const T1& a, const T2& b) -> decltype(a + b) {
  return a + b;
}

// 字符串拼接
template <typename T1, typename T2>
  requires(std::is_convertible<T1, std::string>::value ||
           std::is_convertible<T2, std::string>::value)
inline std::string add(const T1& a, const T2& b) {
  if constexpr (std::is_arithmetic<T1>::value) {
    return std::to_string(a) + std::string(b);
  } else if constexpr (std::is_arithmetic<T2>::value) {
    return std::string(a) + std::to_string(b);
  } else {
    return std::string(a) + std::string(b);
  }
}

}  // namespace helper

#endif  // __MY_HELPER_CPP20_ADD_H__
