# 查找gtest和benchmark库
include(FetchContent)

# 添加本地路径(这是我个人路径,用来存放离线三方库)
# 如需自定义第三方库安装路径,请设置CMAKE_THIRD_PARTY_PATH变量,否则使用默认路径
# googeltest和benchmark都安装在这个路径下, googletest的安装module名是GTest, benchmark的安装模块名是benchmark
# 即 Googletest安装路径名称是GTest, benchmark安装路径名称是benchmark
option(CMAKE_THIRD_PARTY_PATH "Path to offline third-party libraries (optional)" "C:/Person/Work/libs/install")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_THIRD_PARTY_PATH}")

# 先查找,没有就下载库
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    # GIT_REPOSITORY git@github.com:google/googletest.git
    GIT_TAG        v1.17.0
    FIND_PACKAGE_ARGS NAMES GTest
)
FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    # GIT_REPOSITORY git@github.com:google/benchmark.git
    GIT_TAG        v1.9.0 # You can specify a version or branch
    FIND_PACKAGE_ARGS
)
FetchContent_MakeAvailable(googletest benchmark)

# 使能测试
include(GoogleTest)
enable_testing()