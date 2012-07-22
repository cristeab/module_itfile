project(testITFile)

set (testITFile_SRCS
    test_it_file.c)

add_executable (testITFile ${testITFile_SRCS})
IF(WIN32)
target_link_libraries(testITFile
    itfile)
ELSE(WIN32)
target_link_libraries(testITFile
    itfile
    m)
ENDIF(WIN32)
