#pragma once

#include "Runner.hpp"
#include <vector>

namespace aoc {

class Day1 : public Runner {
private:
    std::vector<int> input;
public:
    Day1();

    std::string part1() override;
    std::string part2() override;
};

}
