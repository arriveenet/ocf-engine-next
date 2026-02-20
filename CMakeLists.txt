# ==================================================================================================
# CMake
# ==================================================================================================
cmake_minimum_required (VERSION 3.19)

# ==================================================================================================
# Project declaration
# ==================================================================================================
project(OcfEngine-Next)

# ==================================================================================================
#  Paths
# ==================================================================================================
set(OCF_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(OCF_THIRDPARTY_PATH ${OCF_ROOT_PATH}/thirdparty)

# ==================================================================================================
# General compiler flags
# ==================================================================================================
set(CXX_STANDARD "-std=c++20")

if (MSVC)
    set(CXX_STANDARD "/std:c++20")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_STANDARD} /W0 /Zc:__cplusplus")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_STANDARD} -fstrict-aliasing -Wno-unknown-pragmas -Wno-unused-function -Wno-deprecated-declarations")
endif()

# ==================================================================================================
# Sub-projects
# ==================================================================================================
# Enable -fPIC flag when compiling as shared libs.
if (UNIX AND NOT ANDROID)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()
# Third-party libraries
add_subdirectory(${OCF_THIRDPARTY_PATH}/glad)
add_subdirectory(${OCF_THIRDPARTY_PATH}/glfw)
add_subdirectory(${OCF_THIRDPARTY_PATH}/googletest/ocf)

# Engine and tests
add_subdirectory (${OCF_ROOT_PATH}/engine)
add_subdirectory (${OCF_ROOT_PATH}/tests)