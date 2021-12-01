#include "Day1.hpp"
#include "aoc2021/util/Loader.hpp"

namespace aoc {

Day1::Day1() : input(loadType<int>(1, &sastoi)){

}

std::string Day1::runner(int offset) {
    int count = 0;

    for (int i = offset; i < input.size(); ++i) {
        if (input.at(i) > input.at(i - offset)) {
            ++count;
        }
    }

    return std::to_string(count);

}

std::string Day1::part1() {
    return runner(1);
}

std::string Day1::part2() {
    return runner(3);
}

}
