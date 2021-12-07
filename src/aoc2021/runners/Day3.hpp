#pragma once

#include "Runner.hpp"
#include "aoc2021/util/Loader.hpp"
#include <bitset>

namespace aoc {


class Day3 : public Runner {
public:
    // Fuck bitsets for reversing my fucking integers.
    typedef std::vector<std::string> BitList;
private:
    BitList data = loadFile(/*"3-test"*/ "3");
    long long part2runner(const BitList& input, bool high = false, size_t index = 0);
public:
    StrPair run() override;
};

}
