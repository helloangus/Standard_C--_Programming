cmake_minimum_required(VERSION 3.0.0)
project(example VERSION 0.1.0)

include(CTest)
enable_testing()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


# Add header file include directories
include_directories(${PROJECT_SOURCE_DIR}/include/)

# Add the source in project root directory
aux_source_directory(src DIRSRCS)
add_executable(example example.cpp ${DIRSRCS})  # Add source files