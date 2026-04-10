# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(DemoProject VERSION 1.0.0)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 创建可执行文件
add_executable(demo hello_world.cpp)

# 设置目标属性
target_include_directories(demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 如果有额外的库，可以在这里链接
# target_link_libraries(demo PRIVATE some_library)

# 安装规则（可选）
install(TARGETS demo
    RUNTIME DESTINATION bin
    CONFIGURATIONS Release
)
