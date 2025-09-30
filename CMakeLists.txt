cmake_minimum_required(VERSION 4.1.1)
project(helper)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置头文件目录
include_directories(${CMAKE_SOURCE_DIR}/inc)

# 搜索src下的文件构建库
aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC)

# 构建库
add_library(${PROJECT_NAME} ${SRC})

# 执行python脚本
add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/get_build_time.py
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "正在执行python脚本"
)

# 添加自定义模块路径
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# 启用测试
include(ProjectGoogleTest)

# 定义构建测试的函数
function(build_tests TEST_DIR)
    file(GLOB TEST_SOURCES "${TEST_DIR}/*.cpp")
    foreach(TEST_SOURCE ${TEST_SOURCES})
        get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
        add_executable(${TEST_NAME} ${TEST_SOURCE})
        # 根据测试文件名判断需要链接的库
        set(LINK_LIBS ${PROJECT_NAME})
        string(FIND ${TEST_NAME} "gtest" GTEST_POS)
        string(FIND ${TEST_NAME} "benchmark" BENCHMARK_POS)
        if(NOT ${GTEST_POS} EQUAL -1)
            list(APPEND LINK_LIBS GTest::gtest GTest::gtest_main)
        endif()
        if(NOT ${BENCHMARK_POS} EQUAL -1)
            list(APPEND LINK_LIBS benchmark::benchmark benchmark::benchmark_main)
        endif()
        target_link_libraries(${TEST_NAME} ${LINK_LIBS})
        # 添加测试目标
        if(NOT ${GTEST_POS} EQUAL -1)
            gtest_discover_tests(${TEST_NAME})
        endif()
        # 另一种添加测试的方法
        if(NOT ${BENCHMARK_POS} EQUAL -1)
            # benchmark不需要注册测试, 直接运行即可
            add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
        endif()
    endforeach()
endfunction()

# 调用函数构建测试
build_tests(${CMAKE_SOURCE_DIR}/test)
