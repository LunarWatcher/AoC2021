#pragma once

#include "Runner.hpp"
#include "aoc2021/util/Loader.hpp"

namespace aoc {


class Day7 : public Runner {
private:
    std::vector<int> data = convertStringToIntVec(loadFile("7").at(0), ',');
public:
    StrPair run() override;
};

}
