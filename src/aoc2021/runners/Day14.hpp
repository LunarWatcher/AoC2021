#pragma once

#include "aoc2021/runners/Runner.hpp"

#include <map>
#include <unordered_set>

namespace aoc {

class Day14 : public Runner {
private:
    std::map<std::string, long long> pairs;
    std::map<std::string, std::string> mapping;
    std::map<char, long long> freq;
public:
    Day14();

    StrPair run() override;
    long long score(long long runs);
};

}
