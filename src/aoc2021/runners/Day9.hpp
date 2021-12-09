#pragma once

#include "Runner.hpp"

#include <vector>

namespace aoc {

class Day9 : public Runner {
private:
    std::vector<std::vector<int>> mapData;
public:
    Day9();

    StrPair run() override;
};

}
