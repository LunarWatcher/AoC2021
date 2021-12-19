set (SOURCE_FILES
    aoc2021/Main.cpp
    aoc2021/runners/Day1.cpp
    aoc2021/runners/Day2.cpp
    aoc2021/runners/Day3.cpp
    aoc2021/runners/Day4.cpp
    aoc2021/runners/Day5.cpp
    aoc2021/runners/Day6.cpp
    aoc2021/runners/Day7.cpp
    aoc2021/runners/Day8.cpp
    aoc2021/runners/Day9.cpp
    aoc2021/runners/Day10.cpp
    aoc2021/runners/Day11.cpp
    aoc2021/runners/Day12.cpp
    aoc2021/runners/Day13.cpp
    aoc2021/runners/Day14.cpp
    aoc2021/runners/Day15.cpp
)

add_executable(aoc2021 ${SOURCE_FILES})
target_include_directories(aoc2021 PUBLIC ./)
target_include_directories(aoc2021 PUBLIC ../stc/src)

if (NEEDS_CONAN)
    target_include_directories(aoc2021 PUBLIC ${CONAN_INCLUDE_DIRS})

    target_link_libraries(aoc2021 ${CONAN_LIBS})
endif()
# vim:ft=cmake
