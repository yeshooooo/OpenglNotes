message("main start")

# 定义一个目标列表存储所有的目标，编译连接公共头文件和库
set(ALL_TARGETS hello_window Application hello_triangle hello_triangle_index hello_triangle_exercise1 hello_triangle_exercise2
        hello_triangle_exercise3 shaders_uniform shaders_interpolation shaders_class)
# 添加Utility目录下的文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/LearnOpenGL/Utility LINK_SOURCES)
# learnOpengl
add_executable(hello_window LearnOpenGL/1_getting_started/1_1_hello_window/hello_window.cpp)
add_executable(hello_triangle LearnOpenGL/1_getting_started/2_1_hello_triangle/hello_triangle.cpp)
add_executable(hello_triangle_index LearnOpenGL/1_getting_started/2_1_hello_triangle/hello_triangle_index.cpp)
add_executable(hello_triangle_exercise1 LearnOpenGL/1_getting_started/2_1_hello_triangle/hello_triangle_exercise1.cpp)
add_executable(hello_triangle_exercise2 LearnOpenGL/1_getting_started/2_1_hello_triangle/hello_triangle_exercise2.cpp)
add_executable(hello_triangle_exercise3 LearnOpenGL/1_getting_started/2_1_hello_triangle/hello_triangle_exercise3.cpp)
add_executable(shaders_uniform LearnOpenGL/1_getting_started/3_shaders/shaders_uniform.cpp)
add_executable(shaders_interpolation LearnOpenGL/1_getting_started/3_shaders/shaders_interpolation.cpp)
add_executable(shaders_class LearnOpenGL/1_getting_started/3_shaders/shaders_class.cpp)


# ChernoOpenGL
add_executable(Application ChernoOpenGL/src/Application.cpp)


# 遍历所有target添加头文件和连接库
foreach (target ${ALL_TARGETS})
    target_include_directories(${target} PUBLIC ${LIB_INCLUDE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/LearnOpenGL/Utility/)
#    message("----${CMAKE_CURRENT_SOURCE_DIR}/Utility/")
    target_link_libraries(${target}  PUBLIC ${LINK_LIBS})
    target_link_directories(${target} PUBLIC ${LINK_SOURCES})
endforeach ()
# 查看shader_class所有头文件目录
get_target_property(SHADER_CLADD_INCLUDE_DIRS shaders_class INCLUDE_DIRECTORIES)
message(" shader_class 头文件目录为 ==>" ${SHADER_CLADD_INCLUDE_DIRS})
