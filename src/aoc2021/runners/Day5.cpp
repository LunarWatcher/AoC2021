#include "Day5.hpp"

#include "aoc2021/util/StringUtils.hpp"

namespace aoc {

Day5::Day5() : lines(
        loadType<Line>("5", [](const std::string& in) -> Line {
            auto points = stc::string::splitString(in, " -> ");
            auto a = stc::string::splitString(points.at(0), ',');
            auto b = stc::string::splitString(points.at(1), ',');

            return {
                { std::stoi(a.at(0)), std::stoi(a.at(1)) },
                { std::stoi(b.at(0)), std::stoi(b.at(1)) }
            };
        })) {

}

std::string Day5::part1() {
    for (auto& line : lines) {
        if (line.first.first == line.second.first) {
            int x = line.first.first;
            auto [minY, maxY] = minMax(line.first.second, line.second.second);
            for (int y = minY; y <= maxY; ++y) {
                map[{x, y}] += 1;
            }
        } else if (line.first.second == line.second.second) {
            // X line (y const.)
            int y = line.first.second;
            auto [minX, maxX] = minMax(line.first.first, line.second.first);
            for (int x = minX; x <= maxX; ++x) {
                map[{x, y}] += 1;
            }
            
        }

    }
    int res = 0;
    for (auto& [pair, count] : map) {
        if (count >= 2) {
            ++res;
        }
    }
    return std::to_string(res);
}

std::string Day5::part2() {
    for (auto& line : lines) {
        if (line.first.first != line.second.first && line.first.second != line.second.second) {
            auto [minX, maxX] = minMax(line.first.first, line.second.first);

            auto startY = minX == line.first.first ? line.first.second : line.second.second;
            auto endY = minX == line.first.first ? line.second.second : line.first.second;

            auto negY = startY > endY;
            for (int i = 0; i <= maxX - minX; ++i) {
                map[{minX + i, startY + i * (negY ? -1 : 1)}] += 1;
            }
            std::cout << std::endl;
            
        }

    }
    int res = 0;
    for (auto& [pair, count] : map) {
        if (count >= 2) {
            ++res;
        }
    }
    return std::to_string(res);
}

}
