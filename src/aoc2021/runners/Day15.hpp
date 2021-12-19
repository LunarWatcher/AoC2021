#pragma once

#include "aoc2021/runners/Runner.hpp"
namespace aoc {

class Day15 : public Runner {
private:
    size_t width, height;
    std::vector<std::vector<int>> data;
public:
    Day15();

    StrPair run() override;

    int search(const std::vector<std::vector<int>>& data);
};

}
