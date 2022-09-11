cmake_minimum_required (VERSION 3.1)
project (Lab6)
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(ProjectLibrary SHARED ${SOURCES})

add_executable(main main.cpp)
target_link_libraries(main ProjectLibrary)
