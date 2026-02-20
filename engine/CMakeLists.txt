cmake_minimum_required (VERSION 3.19)
project(OcfEngine_lib C ASM)

set(TARGET ocfengine)
set(PUBLIC_HDR_DIR include)

# ==================================================================================================
# Sources and headers
# ==================================================================================================

set(PUBLIC_HDRS
    include/ocf/Component.h
    include/ocf/Engine.h
    include/ocf/Node.h
    include/ocf/Scene.h
    include/ocf/platform/Window.h
)

set(PRIVATE_HDRS
)

set(SRCS
    src/Component.cpp
    src/Engine.cpp
    src/Node.cpp
    src/Scene.cpp
)


list(APPEND PRIVATE_HDRS ${OCF_BACKEND_HEADER})
list(APPEND SRCS ${OCF_BACKEND_SRC})

# ==================================================================================================
# Includes & target definition
# ==================================================================================================
include_directories(${PUBLIC_HDR_DIR})
include_directories(src)

#building a library
add_library(${TARGET} STATIC ${PUBLIC_HDRS} ${PRIVATE_HDRS} ${SRCS})

target_include_directories(${TARGET} PUBLIC ${PUBLIC_HDR_DIR})

set_target_properties(${TARGET} PROPERTIES FOLDER ocfengine)

# ==================================================================================================
# Dependencies
# ==================================================================================================
target_link_libraries(${TARGET} PUBLIC glad)
target_link_libraries(${TARGET} PUBLIC glfw)

# ==================================================================================================
# Compiler flags
# ==================================================================================================
if (MSVC)
    set(OCF_WARNINGS /W4)
else()
    set(OCF_WARNINGS
            -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers
            -Wextra-semi -Wdeprecated -Wundef
            -Wnon-virtual-dtor -Wimplicit-fallthrough
            -Wno-template-id-cdtor
    )
endif()

target_compile_options(${TARGET} PRIVATE ${OCF_WARNINGS})

# ==================================================================================================
# Sub-projects
# ==================================================================================================
add_subdirectory(test)