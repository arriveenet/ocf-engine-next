# ==================================================================================================
# Tests
# ==================================================================================================
add_executable(test_${TARGET}
    test_node.cpp
)
target_link_libraries(test_${TARGET} PRIVATE gtest PRIVATE ocfengine)
set_target_properties(test_${TARGET} PROPERTIES FOLDER Tests)
