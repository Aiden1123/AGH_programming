cmake_minimum_required (VERSION 3.1)
project (Lab2)
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(ProjectLibrary SHARED ${SOURCES})

add_executable(Lab2 main.cpp)
target_link_libraries(Lab2 ProjectLibrary)
