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

#define Day(x) std::make_shared<aoc::Day##x>()

int main(int argc, char* argv[]) {
    std::vector<std::shared_ptr<aoc::Runner>> runners = {
        Day(1),
        Day(2),
        Day(3),
        Day(4),
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
        std::cout << "Part 1: " << runners.at(i)->part1() << std::endl;
        std::cout << "Part 2: " << runners.at(i)->part2() << std::endl;
    }

}
