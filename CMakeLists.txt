cmake_minimum_required(VERSION 3.10)
project(AoC2021)

# Includes {{{
include(CheckIncludeFileCXX)
# }}}

set (CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
endif()

if (ENABLE_PROFILING)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
endif()

set (NEEDS_CONAN OFF)

#set (CMAKE_REQUIRED_INCLUDES "/usr/local/include")
#CHECK_INCLUDE_FILE_CXX(ranges HAS_RANGES)

#if (NOT HAS_RANGES)
    #set (NEEDS_CONAN ON)
    #include(${CMAKE_BINARY_DIR}/conan.cmake)

    #conan_cmake_configure (REQUIRES 
                            #range-v3/0.11.0 
                            #GENERATORS cmake)
    #conan_cmake_autodetect (settings)
    #conan_cmake_install (PATH_OR_REFERENCE . BUILD missing SETTINGS ${settings})

    #include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    #conan_basic_setup()
#endif()

add_subdirectory(src)
# vim:ft=cmake
