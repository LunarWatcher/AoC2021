#include "Day2.hpp"

#include "aoc2021/util/Loader.hpp"

namespace aoc {

Day2::Day2() : data(loadType<std::pair<Direction, int>>("2", [](const std::string& in) -> std::pair<Direction, int> {
            Direction dir;
            switch(in.at(0)) {
            case 'f':
                dir = FORWARD;
                break;
            case 'd':
                dir = DOWN;
                break;
            case 'u':
                dir = UP;
                break;
            }
            return {dir, std::stoi(in.substr(in.find(' ') + 1))};
        })){}

StrPair Day2::run() {
    std::string a, b;

    {
        long long h = 0, d = 0;

        for (auto& move : data) {
            switch (move.first) {
            case UP:
                d -= move.second;
                break;
            case DOWN:
                d += move.second;
                break;
            case FORWARD:
                h += move.second;
                break;
            }
        }

        a = std::to_string(h * d);
    }
    {
        long long h = 0, d = 0, aim = 0;

        for (auto& move : data) {
            switch (move.first) {
            case UP:
                aim -= move.second;
                break;
            case DOWN:
                aim += move.second;
                break;
            case FORWARD:
                h += move.second;
                d += aim * move.second;
                break;
            }
        }

        b = std::to_string(h * d);
    }
    return {a, b};
}

}
