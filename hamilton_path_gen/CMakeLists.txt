
cmake_minimum_required (VERSION 2.8)

project ("hamilton_path_gen")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/inc )

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/inc/*.hh)

# Add source to this project's executable.
add_executable (hamilton_path_gen hamilton_path_gen.cc hamilton_path_gen.hh ${sources} ${headers})

# TODO: Add tests and install targets if needed.
