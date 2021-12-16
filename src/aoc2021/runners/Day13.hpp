#pragma once

#include "Runner.hpp"
#include <unordered_set>

namespace aoc {


struct PairHash {
    size_t operator()(const std::pair<int, int>& pair) const {
        return size_t(pair.first) << 32 | pair.second;
    }
};
struct PairEquals {
    size_t operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        return a.first == b.first && a.second == b.second;
    }
};

class Day13 : public Runner {
private:
    std::unordered_set<std::pair<int, int>, PairHash, PairEquals> basePairs;
    std::vector<std::pair<bool, int>> folds;
public:
    Day13();

    StrPair run() override;
};

}
