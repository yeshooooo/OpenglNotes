message("main start")
add_executable(main LearnOpenGL/1_getting_started/1_1_hello_window/hello_window.cpp)

target_include_directories(main PUBLIC ${LIB_INCLUDE_PATH})
target_link_libraries(main PUBLIC ${LINK_LIBS})