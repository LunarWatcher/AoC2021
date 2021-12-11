#include "Day11.hpp"

namespace aoc {

StrPair Day11::run() {
    int a = 0, b = 100;


    for (int i = 0; i < 100; ++i) {
        a += simulate();
    }
    while (true) {
        simulate();
        ++b;
        for (auto& row : data) {
            for (auto& cell : row) {
                if (cell != 0) goto cont;
            }
        }
        break;
cont: continue;
    }
    return {
        std::to_string(a), std::to_string(b)
    };
}

int Day11::simulate() {
    int flashes = 0;
    for (auto& row : data) {
        for (auto& cell : row) {
            ++cell;
        }
    }
    while (true) {
        bool found = false;
        for (int y = 0; y < MAP_SIZE; ++y) {
            for (int x = 0; x < MAP_SIZE; ++x) {
                auto& cell = data.at(y).at(x);
                if (cell > 9) {
                    cell = 0;
                    flash(x, y);
                    ++flashes;
                    found = true;
                }
            }
        }
        if (!found) {
            break;
        }
    }
    return flashes;
}

void Day11::flashTarget(int x, int y) {
    if (x < 0 || y < 0 || y >= MAP_SIZE || x >= MAP_SIZE) return;
    // we abuse 0 to indicate a flash this step.
    if (data.at(y).at(x) == 0) return;
    data.at(y).at(x) += 1;
}

void Day11::flash(int x, int y) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            flashTarget(x + i, y + j);
        }
    }
}

}
