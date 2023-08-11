cmake_minimum_required(VERSION 3.22)
project(OpenglNotes
        VERSION 0.0.1
        DESCRIPTION "learnopengl notes"
        LANGUAGES C CXX

)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)

add_subdirectory(external/glfw)
add_subdirectory(external/glad)

# 设置头文件目录和链接库

set(LIB_INCLUDE_PATH
        ${PROJECT_SOURCE_DIR}/external/glad/include/
        ${PROJECT_SOURCE_DIR}/external/glfw/include/
)

set(LINK_LIBS glfw glad)
add_subdirectory(src)




