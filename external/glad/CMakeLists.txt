project(glad
        VERSION 0.0.1
        LANGUAGES C
        DESCRIPTION "Add cmake support for glad"
        HOMEPAGE_URL "github/yeshooooo"

)

set(SOURCE_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/include/glad/glad.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/KHR/khrplatform.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c"
)
add_library(glad STATIC ${SOURCE_FILES})

target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)