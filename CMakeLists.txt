cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

include(FetchContent)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib
  GIT_TAG 5.5
  GIT_SHALLOW ON
)
FetchContent_MakeAvailable(raylib)

add_subdirectory(src)
add_subdirectory(inc)

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE raylib)
