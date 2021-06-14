# GraphDependencyTree

## Compilation

### Requirements

* CMake 3.17.3 or newer

Compilation has been tested on Windows with CMake + Ninja and MSVC 
( Works from developer command prompt and VS2019 too. )
It should be working with gcc and clang too.

VS2019 build steps:
* Open project folder
* Generate Cache for GraphDependencyTree
* Build

Commandline build steps:
* Open x64 Native Command Prompt for VS2019
* Navigate to project folder
* mkdir build
* cd build
* cmake .. -G Ninja
* Ninja

## Testing

Application can be tested with `.\build\src\GraphDependencyTreeTest\GraphDependencyTreeTest(.exe)`
For addition test cases graphdependencytreetest class can be amended, additional test functions can be added.
