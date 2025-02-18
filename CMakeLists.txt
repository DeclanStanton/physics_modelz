cmake_minimum_required(VERSION 3.10)
project(ptcl_circle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(ptcl_circle ptcl_circle.cpp)
target_link_libraries(ptcl_circle PRIVATE SFML::Graphics SFML::Window SFML::System)
