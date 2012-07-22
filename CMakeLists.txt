project (itFileModule)

cmake_minimum_required(VERSION 2.8)

include_directories (${CMAKE_SOURCE_DIR}/src)

set (itFileModule_SRCS
    src/binfile.cpp
    src/itfile.cpp
    src/vec.cpp
    src/mat.cpp
    src/copy_vector.cpp
    src/itassert.cpp
    src/misc.cpp
    src/converters.cpp
    src/help_functions.cpp
    src/matfunc.cpp
    src/inv.cpp
    src/schur.cpp
    src/binary.cpp
    src/it_file.cpp
    src/itcompat.cpp)

add_subdirectory (test)

add_library (itfile STATIC ${itFileModule_SRCS})
