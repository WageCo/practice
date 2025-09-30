#ifndef __MY_HELPER_CPP20_ADD_H__
#define __MY_HELPER_CPP20_ADD_H__

#include <type_traits>

namespace helper {

// 删除指针类型的支持, 以避免潜在的悬空指针问题, 并确保类型安全
// 通过concepts实现
template <typename T1, typename T2>
  requires(!std::is_pointer<T1>::value && !std::is_pointer<T2>::value)
inline auto add(const T1& a, const T2& b) -> decltype(a + b) {
  return a + b;
}

}  // namespace helper

#endif  // __MY_HELPER_CPP20_ADD_H__
