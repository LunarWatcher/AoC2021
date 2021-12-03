#include "Day3.hpp"

#include <string>
#include <bitset>
#include <algorithm>

namespace aoc {


long long Day3::part2runner(const BitList& input, bool high, size_t index) {
    if (input.size() == 1) {
        return std::stoull(input.at(0), nullptr, 2);
    }

    BitList one, zero;
    for (auto& set : input) {
        if (set.at(index) == '1') {
            one.push_back(set);
        } else zero.push_back(set);
    }

    if (high) {
        return part2runner(one.size() >= zero.size() ? one : zero, high, index + 1);
    }
    return part2runner(one.size() >= zero.size() ? zero : one, high, index + 1);
}

std::string Day3::part1() {
    size_t len = data.at(0).size();

    int gamma = 0, epsilon = 0;

    for (int i = 0; i < len; ++i) {
        int one = std::count_if(data.cbegin(), data.cend(), [i](const std::string& in) { return in.at(i) == '1'; });
        int high = 1;
        if (one < data.size() / 2) {
            high = 0;
        }
        gamma |= high << (len - i - 1);
        epsilon |= (!high) << (len - i - 1);
    }
    return std::to_string(gamma * epsilon);
}

std::string Day3::part2() {
    return std::to_string(part2runner(data, true) * part2runner(data, false));
}

}
