cmake_minimum_required (VERSION 3.19)
project(OcfEngine_lib C ASM)

set(TARGET ocfengine)
set(PUBLIC_HDR_DIR include)

# ==================================================================================================
# Options
# ==================================================================================================
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# ==================================================================================================
# Sources and headers
# ==================================================================================================

set(PUBLIC_HDRS
    include/ocf/2d/Sprite.h
    include/ocf/math/constants.h
    include/ocf/math/constants.inl
    include/ocf/math/geometric.h
    include/ocf/math/geometric.inl
    include/ocf/math/mat2.h
    include/ocf/math/mat2.inl
    include/ocf/math/mat3.h
    include/ocf/math/mat3.inl
    include/ocf/math/mat4.h
    include/ocf/math/mat4.inl
    include/ocf/math/matrix_transform.h
    include/ocf/math/matrix_transform.inl
    include/ocf/math/MaxRectsBinPack.h
    include/ocf/math/qualifie.h
    include/ocf/math/quat.h
    include/ocf/math/quat.inl
    include/ocf/math/Rect.h
    include/ocf/math/RectBinPack.h
    include/ocf/math/vec2.h
    include/ocf/math/vec2.inl
    include/ocf/math/vec3.h
    include/ocf/math/vec3.inl
    include/ocf/math/vec4.h
    include/ocf/math/vec4.inl
    include/ocf/platform/Application.h
    include/ocf/platform/Window.h
    include/ocf/scene/Component.h
    include/ocf/scene/Engine.h
    include/ocf/scene/Node.h
    include/ocf/scene/Scene.h
)

set(PRIVATE_HDRS
    src/platform/GLFWWindow.h
)

set(SRCS
    src/2d/Sprite.cpp
    src/math/MaxRectsBinPack.cpp
    src/math/Rect.cpp
    src/platform/Application.cpp
    src/platform/Window.cpp
    src/platform/GLFWWindow.cpp
    src/scene/Component.cpp
    src/scene/Engine.cpp
    src/scene/Node.cpp
    src/scene/Scene.cpp
)


list(APPEND PRIVATE_HDRS ${OCF_BACKEND_HEADER})
list(APPEND SRCS ${OCF_BACKEND_SRC})

# ==================================================================================================
# Includes & target definition
# ==================================================================================================
include_directories(${PUBLIC_HDR_DIR})
include_directories(src)

#building a library
add_library(${TARGET} ${PUBLIC_HDRS} ${PRIVATE_HDRS} ${SRCS})
if(BUILD_SHARED_LIBS)
    target_compile_definitions(${TARGET} PRIVATE OCF_LIBRARY_EXPORTS)
else()
    target_compile_definitions(${TARGET} PUBLIC OCF_LIBRARY_STATIC)
endif()

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
# add_subdirectory(test)