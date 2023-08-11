message("main start")
add_executable(main main.cpp)

target_include_directories(main PUBLIC ${LIB_INCLUDE_PATH})
target_link_libraries(main PUBLIC ${LINK_LIBS})