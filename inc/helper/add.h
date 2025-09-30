#ifndef __MY_HELPER_ADD_H__
#define __MY_HELPER_ADD_H__

#include "version.h"

// 根据C++标准选择不同的实现文件
#ifdef __HELPER_IMP_CPP20_OR_LATER__
#include "cpp20/add.h"
#else
#include "cpp17/add.h"
#endif

#endif  // __MY_HELPER_ADD_H__