add_executable(
    ecs_test
    Ecs.test.cpp
)

set_target_properties(
    ecs_test PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

target_link_libraries(
    ecs_test
    libsatk
)