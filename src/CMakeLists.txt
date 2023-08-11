message("main start")

# 定义一个目标列表存储所有的目标，编译连接公共头文件和库
set(ALL_TARGETS hello_window Application)
add_executable(hello_window LearnOpenGL/1_getting_started/1_1_hello_window/hello_window.cpp)

# ChernoOpenGL
add_executable(Application ChernoOpenGL/src/Application.cpp)

# 遍历所有target添加头文件和连接库
foreach (target ${ALL_TARGETS})
    target_include_directories(${target} PUBLIC ${LIB_INCLUDE_PATH})
    target_link_libraries(${target}  PUBLIC ${LINK_LIBS})
endforeach ()