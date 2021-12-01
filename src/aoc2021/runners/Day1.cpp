#include "Day1.hpp"
#include "aoc2021/util/Loader.hpp"

namespace aoc {

Day1::Day1() : input(loadType<int>(1, &sastoi)){

}

std::string Day1::part1() {
    int count = 0;

    for (int i = 1; i < input.size(); ++i) {
        if (input.at(i) > input.at(i - 1)) {
            ++count;
        }
    }

    return std::to_string(count);
}

std::string Day1::part2() {
    int count = -1;
    int last = 0;

    for (int i = 0; i < input.size() - 2; ++i) {
        int sum = input.at(i)
            + input.at(i + 1)
            + input.at(i + 2);
        if (sum > last) {
            ++count;
        }
        last = sum;
    }

    return std::to_string(count);
}

}
