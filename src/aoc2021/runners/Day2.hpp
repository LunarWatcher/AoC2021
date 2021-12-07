#pragma once

#include "Runner.hpp"
#include <vector>

namespace aoc {


class Day2 : public Runner {
public:
    enum Direction {
        FORWARD, DOWN, UP
    };
private:
    std::vector<std::pair<Direction, int>> data;
public:
    Day2();

    StrPair run() override;

};

}
