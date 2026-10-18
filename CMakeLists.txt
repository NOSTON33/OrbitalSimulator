cmake_minimum_required(VERSION 3.20)

project(OrbitalSimulator LANGUAGES CXX)

add_subdirectory(Core)
add_subdirectory(Physics)
add_subdirectory(Integrator)
add_subdirectory(app)

include(CTest)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

