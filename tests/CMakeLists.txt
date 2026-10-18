include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(OrbitalTests
    IntegratorTests.cpp
)

target_link_libraries(OrbitalTests
    PRIVATE
        Integrator
        GTest::gtest_main
        Physics
)

include(GoogleTest)

gtest_discover_tests(OrbitalTests)