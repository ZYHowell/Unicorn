cmake_minimum_required(VERSION 3.10.2)
project(unicorn)
set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}   -g")
include_directories(
        ${PROJECT_SOURCE_DIR}/generated/
        ${PROJECT_SOURCE_DIR}/third_party/
        ${PROJECT_SOURCE_DIR}/third_party/runtime/src
        ${PROJECT_SOURCE_DIR}/src/
)
set(src_dir
        ${PROJECT_SOURCE_DIR}/generated/AssembLexer.cpp
        ${PROJECT_SOURCE_DIR}/generated/AssembParser.cpp
        ${PROJECT_SOURCE_DIR}/generated/AssembListener.cpp
        ${PROJECT_SOURCE_DIR}/generated/AssembBaseListener.cpp
        )
file(GLOB antlr4-cpp-src
        ${PROJECT_SOURCE_DIR}/third_party/runtime/src/*.cpp
        ${PROJECT_SOURCE_DIR}/third_party/runtime/src/atn/*.cpp
        ${PROJECT_SOURCE_DIR}/third_party/runtime/src/dfa/*.cpp
        ${PROJECT_SOURCE_DIR}/third_party/runtime/src/misc/*.cpp
        ${PROJECT_SOURCE_DIR}/third_party/runtime/src/support/*.cpp
        ${PROJECT_SOURCE_DIR}/third_party/runtime/src/tree/*.cpp
        ${PROJECT_SOURCE_DIR}/third_party/runtime/src/tree/pattern/*.cpp
        ${PROJECT_SOURCE_DIR}/third_party/runtime/src/tree/xpath/*.cpp
        )
add_library (antlr4-cpp-runtime ${antlr4-cpp-src})
add_executable(unicorn ${src_dir} src/main.cpp)
target_link_libraries(unicorn antlr4-cpp-runtime)