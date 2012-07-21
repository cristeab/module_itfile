project (itFileModule)

cmake_minimum_required(VERSION 2.8)

include_directories (${CMAKE_SOURCE_DIR}/src)

set (itFileModule_SRCS
    src/binfile.cpp
    src/itfile.cpp
    src/vec.cpp
    src/it_file.cpp)

add_library (itfile SHARED ${itFileModule_SRCS})
