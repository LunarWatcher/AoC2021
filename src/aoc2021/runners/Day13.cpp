#include "Day13.hpp"
#include "stc/StringUtil.hpp"

namespace aoc {

Day13::Day13() {
    std::vector<std::string> lines = loadFile("13");
    bool state = false;
    for (auto& line : lines) {
        if (line == "") {
            state = true;
            continue;
        }
        if (!state) {
            auto vec = stc::string::split(line, ',');
            basePairs.insert({
                std::stoi(vec.at(0)),
                std::stoi(vec.at(1))
            });
        } else {
            auto equals = line.find('=');
            char axis = line.at(equals - 1);
            int foldCoords = std::stoi(line.substr(equals + 1));

            folds.push_back({
                axis == 'x',
                foldCoords
            });
        }
    }
}

StrPair Day13::run() {
    int a = -1;

    int maxX, maxY;

    for (auto& [isX, coords] : folds) {
        maxX = 0, maxY = 0;
        decltype(basePairs) newPairs;
        for (auto [x, y] : basePairs) {
            if (isX && x > coords) {
                x = coords - abs(x - coords);
            } else if (!isX && y > coords) {
                y = coords - abs(y - coords);
            }
            maxX = std::max(x, maxX);
            maxY = std::max(y, maxY);
            newPairs.insert({x, y});
        }
        basePairs = newPairs;
        if (a == -1) {
            a = basePairs.size();
        }
    }
    std::string b = "\n";

    for (int y = 0; y <= maxY; ++y) {
        for (int x = 0; x <= maxX; ++x) {
            if (basePairs.find({x, y}) != basePairs.end()) {
                b += "#";
            } else b += ".";
        }
        b += "\n";
    }
    
    return {std::to_string(a), b};
}

}
