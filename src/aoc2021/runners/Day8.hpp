#pragma once

#include  "Runner.hpp"

#include <vector>

namespace aoc {

class Day8 : public Runner {
public:
    typedef std::pair<std::vector<std::string>, std::vector<std::string>> InOutPair;
private:
    std::vector<InOutPair> data;
public:
    Day8();

    StrPair run() override;
};

}
