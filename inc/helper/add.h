#ifndef __MY_HELPER_ADD_H__
#define __MY_HELPER_ADD_H__

#include <iostream>

#include "version.h"

// 根据C++标准选择不同的实现文件
#ifdef __HELPER_IMP_CPP20_OR_LATER__
#include "cpp20/add.h"
#else
#include "cpp17/add.h"
#endif

namespace debug {
// 包装函数, 增加类型打印, 比如调用debug::add("Hello, ",
// "World!")等于先打印类型再调用add函数
template <typename T1, typename T2>
inline auto add(const T1& a, const T2& b) -> decltype(helper::add(a, b)) {
  std::cout << "Debug: Adding types " << typeid(a).name() << " and "
            << typeid(b).name() << std::endl;
  return helper::add(a, b);
}
}  // namespace debug

#endif  // __MY_HELPER_ADD_H__