#pragma once

#include "Runner.hpp"

#include <map>

namespace aoc {

class Day10 : public Runner {
private:
    std::vector<std::string> data;

    inline static const std::map<char, char> pairMaps = {
        {'{', '}'},
        {'(', ')'},
        {'<', '>'},
        {'[', ']'}
    };
public:
    Day10();

    StrPair run() override;
};

}
