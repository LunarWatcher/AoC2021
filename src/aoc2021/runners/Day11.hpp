#pragma once

#include "Runner.hpp"

namespace aoc {

class Day11 : public Runner {
public:
    inline static constexpr int MAP_SIZE = 10;
private:
    std::vector<std::vector<int>> data = loadType<std::vector<int>>("11",
        [](const std::string& in) {
            std::vector<int> out;
            for (auto& chr : in) out.push_back(chr - '0');
            return out;
        });

    void flashTarget(int x, int y);
public:
    StrPair run() override;

    void flash(int x, int y);
    int simulate();
};

}
