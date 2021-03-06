#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <memory>

#include "runners/Runner.hpp"

#include "runners/Day1.hpp"
#include "runners/Day2.hpp"
#include "runners/Day3.hpp"
#include "runners/Day4.hpp"
#include "runners/Day5.hpp"
#include "runners/Day6.hpp"
#include "runners/Day7.hpp"
#include "runners/Day8.hpp"
#include "runners/Day9.hpp"
#include "runners/Day10.hpp"
#include "runners/Day11.hpp"
#include "runners/Day12.hpp"
#include "runners/Day13.hpp"
#include "runners/Day14.hpp"
#include "runners/Day15.hpp"
//#include "runners/Day16.hpp"
//#include "runners/Day17.hpp"
//#include "runners/Day18.hpp"
//#include "runners/Day19.hpp"
//#include "runners/Day20.hpp"
//#include "runners/Day21.hpp"
//#include "runners/Day22.hpp"
//#include "runners/Day23.hpp"
//#include "runners/Day24.hpp"
//#include "runners/Day25.hpp"

#include <chrono>

#define Day(x) std::make_shared<aoc::Day##x>()

int main(int argc, char* argv[]) {
    std::vector<std::shared_ptr<aoc::Runner>> runners = {
        Day(1),  Day(2),  Day(3),  Day(4),  Day(5),
        Day(6),  Day(7),  Day(8),  Day(9),  Day(10),
        Day(11), Day(12), Day(13), Day(14), Day(15),
    };

    int min, max;
    if (argc == 1) {
        min = 0;
        max = runners.size();
    } else {
        min = max = std::stoi(argv[1]) - 1;
        ++max;
    }
    for (int i = min; i < max; ++i) {

        std::cout << "##### Day " << i + 1 << " #####" << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        aoc::StrPair result = runners.at(i)->run();
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Part 1: " << result.first << std::endl;
        std::cout << "Part 2: " << result.second << std::endl;
        std::cout << "(Total time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms)\n";
    }

}
