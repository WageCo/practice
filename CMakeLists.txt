cmake_minimum_required(VERSION 3.20.0)
project(helper)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# 设置头文件目录
include_directories(${CMAKE_SOURCE_DIR}/inc)

# 搜索src下的文件构建库
aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC)

# 构建库
add_library(${PROJECT_NAME} ${SRC})

# 构建函数

# 查找gtest和benchmark库
enable_testing()
find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

# 扫描test下的文件，每个cpp文件编译为独立测试程序
file(GLOB TEST_SOURCES "${CMAKE_SOURCE_DIR}/test/*.cpp")
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} 
        ${PROJECT_NAME}
        
        GTest::gtest
        benchmark::benchmark
        )
    # 添加测试目标
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

# 优化编译选项
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-O3 -DNDEBUG)
else()
    add_compile_options(-g -O0 -Wall -Wextra)
endif()
