# This is a minimal CMakeLists files which include the Yoctopuce C++ lib.
cmake_minimum_required (VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)  # Sets the C++ standard

project (test)

# Add the Sources subfolder of the Yoctopuce C++ library.
include_directories (${YOCTO_PATH}/Sources)

# Add executable called "demo" that is built from the source files "main.pp".
add_executable (test test.cpp)

# Link the executable to the Yoctopuce C++ library (YoctoLib).
target_link_libraries (${PROJECT_NAME} yocto)
