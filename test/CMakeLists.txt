project(testITFile)

set (testITFile_SRCS
    test_it_file.c)

add_executable (testITFile ${testITFile_SRCS})
target_link_libraries(testITFile
    ${CMAKE_CURRENT_BINARY_DIR}/../libitfile.so
    m)
