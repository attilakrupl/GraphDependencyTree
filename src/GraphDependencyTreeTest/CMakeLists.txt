include_directories( "${CMAKE_SOURCE_DIR}/src/GraphDependencyTree/" )

add_executable (GraphDependencyTreeTest "main.cpp"  "stdafx.h" "stdafx.cpp" "graphdependencytreetest.h" "graphdependencytreetest.cpp")
add_test( Testing GraphDependencyTreeTest )

target_link_libraries( GraphDependencyTreeTest GraphDependencyTree )
add_dependencies( GraphDependencyTreeTest GraphDependencyTree )

