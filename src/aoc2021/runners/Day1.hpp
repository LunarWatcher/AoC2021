#pragma once

#include "Runner.hpp"
#include <vector>

namespace aoc {

class Day1 : public Runner {
private:
    std::vector<int> input;

    std::string runner(int offset);
public:
    Day1();

    StrPair run() override;
};

}
