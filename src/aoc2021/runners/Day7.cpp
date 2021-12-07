#include "Day7.hpp"

#include <math.h>
#include <numeric>

namespace aoc {

std::pair<std::string, std::string> Day7::run() {
    std::sort(data.begin(), data.end());
    int bot = std::floor(this->data.size() / 2.0) - 1;
    int alignTarget;
    if (data.size() % 2 != 0) {
        alignTarget = data.at(bot);
    } else {
        alignTarget = std::floor((data.at(bot) + data.at(bot + 1)) / 2.0);
    }
    std::cout << "Aligning to " << alignTarget << std::endl;
    int sumA = 0;
    for (int crab : this->data) {
        sumA += std::abs(alignTarget - crab);
    }

    int max = *std::max_element(data.begin(), data.end());

    long long sumB = 9999999999ll;
    for (int i = 0; i < max; ++i) {
        long long sumBNew = 0;
        for (int crab : this->data) {
            long long steps = std::abs(i - crab);
            for (int i = 1; i <= steps; ++i) {
                sumBNew += i;
            }
        }
        sumB = std::min(sumB, sumBNew);
    }
    return {
        std::to_string(sumA),
        std::to_string(sumB)
    };
}

}
