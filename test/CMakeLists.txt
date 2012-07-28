project(testITFile)

set_source_files_properties(test_it_file.c LANGUAGE C)

set (testITFile_SRCS
    test_it_file.c)

add_executable (testITFile ${testITFile_SRCS})

set_target_properties(testITFile PROPERTIES LINKER_LANGUAGE C)

IF(WIN32)
target_link_libraries(testITFile
    itfile)
ELSE(WIN32)
target_link_libraries(testITFile
    itfile
    m)
ENDIF(WIN32)
