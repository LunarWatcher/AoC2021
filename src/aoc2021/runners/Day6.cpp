#include "Day6.hpp"

namespace aoc {

Day6::Day6() : rawData(convertStringToIntVec(loadFile("6").at(0), ',')) {
    for (auto& state : rawData) {
        states[state] += 1ll;
    }
    states[0] = 0;
}

long long Day6::simulate(int days) {
    for (int i = 0; i < days - executed; ++i) {
        for (int j = 0; j <= 8; ++j) {
            states[j - 1] = states[j];
        }
        states[6] += states[-1];
        states[8] = states[-1];
        states[-1] = 0;
    }
    executed += days;
    long long sum = 0;
    for (auto& [_, inState] : states) {
        sum += inState;
    }
    return sum;
}

StrPair Day6::run() {
    return {
        std::to_string(simulate(80)),
        std::to_string(simulate(256))
    };
}

}
