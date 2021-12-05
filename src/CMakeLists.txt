set (SOURCE_FILES
    aoc2021/Main.cpp
    aoc2021/runners/Day1.cpp
    aoc2021/runners/Day2.cpp
    aoc2021/runners/Day3.cpp
    aoc2021/runners/Day4.cpp
    aoc2021/runners/Day5.cpp
)

add_executable(aoc2021 ${SOURCE_FILES})
target_include_directories(aoc2021 PUBLIC ./)
if (NEEDS_CONAN)
    target_include_directories(aoc2021 PUBLIC ${CONAN_INCLUDE_DIRS})

    target_link_libraries(aoc2021 ${CONAN_LIBS})
endif()
# vim:ft=cmake
