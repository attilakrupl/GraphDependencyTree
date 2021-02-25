cmake_minimum_required( VERSION 3.17.3 )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("GraphDependencyTree")

ENABLE_TESTING()

add_subdirectory ("src/GraphDependencyTree")
add_subdirectory ("src/GraphDependencyTreeTest")
