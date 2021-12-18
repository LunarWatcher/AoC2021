#include "Day14.hpp"
#include "aoc2021/util/Loader.hpp"
#include "stc/StringUtil.hpp"
#include <algorithm>
#include <math.h>

namespace aoc {

Day14::Day14() {
    auto lines = loadFile("14");

    std::string rPairs = lines.at(0);
    for (int i = 0; i < rPairs.size(); ++i) {
        freq[rPairs.at(i)]++;
        if (i != rPairs.size() - 1) {
            pairs[rPairs.substr(i, 2)]++;
        }
    }
    for (int i = 2; i < lines.size(); ++i) {
        auto split = stc::string::split(lines.at(i), " -> ");
        mapping[split.at(0)] = split.at(1);
    }
}

long long Day14::score(long long runs) {

    for (int i = 0; i < runs; ++i) {
        size_t pos = 0;
        auto old = pairs;
        pairs.clear();
        for (auto& [pair, count] : old) {
            //std::cout << pair << ": " << count << std::endl;

            if (mapping.contains(pair)) {
                std::string map = mapping[pair];
                pairs[pair.at(0) + map] += count;
                pairs[map + pair.at(1)] += count;
                freq[map.at(0)] += count;
            }
        }
    }

    return (std::max_element(freq.begin(), freq.end(), [](const auto& p1, const auto& p2) {
        return p1.second < p2.second;
    })->second -
    std::min_element(freq.begin(), freq.end(), [](const auto& p1, const auto& p2) {
        return p1.second < p2.second;
    })->second);
}

StrPair Day14::run() {
    return {std::to_string(score(10)), std::to_string(score(30))};
}

}
