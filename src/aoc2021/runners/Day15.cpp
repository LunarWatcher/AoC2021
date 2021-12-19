#include "Day15.hpp"

#include <cmath>
#include <queue>
#include <utility>

namespace aoc {

Day15::Day15() {
    auto data = loadFile("15-test");
    width = data.at(0).size();
    height = data.size();

    for (auto& row : data) {
        std::vector<int> risks;
        for (auto& col : row) {
            risks.push_back(col - '0');
        }
        this->data.push_back(risks);
    }
}

StrPair Day15::run() {
    std::string a, b;
    a = std::to_string(search(data));
    {
        auto data = this->data;
        data.resize(height * 5);

        for (int y = 0; y < data.size(); ++y) {
            auto yCell = std::floor(y / height);
            data.at(y).resize(5 * width);
            for (int x = 0; x < 5 * width; ++x) {
                if (y < height && x < width) continue;
                auto xCell = std::floor(x / width);
                if (xCell == 0) {
                    data.at(y).at(x) = std::max(1, (data.at(y - height).at(x) + 1) % 10);
                } else {
                    data.at(y).at(x) = std::max(1, (data.at(y).at(x - width) + 1) % 10);
                }
            }
        }
        b = std::to_string(search(data));
    }
    return {a, b};
}

int Day15::search(const std::vector<std::vector<int>>& data) {
    auto dest = std::pair<int, int>{data.size() - 1, data.at(0).size() - 1};
    static const std::vector<std::pair<int, int>> changes = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    std::vector<std::vector<int>> cumulativeRisks;
    cumulativeRisks.resize(dest.second + 1);
    for (auto& row : cumulativeRisks) {
        row.resize(dest.first + 1);
        for (auto& cell : row) cell = 99999999;
    }

    cumulativeRisks.at(0).at(0) = 0;

    std::queue<std::pair<int, int>> toVisit;
    std::pair<int, int> start(0, 0);
    toVisit.push(start);

    do {
        auto next = toVisit.front();
        toVisit.pop();

        // We'll go ahead and assume a path never goes up or right
        auto currRisk = cumulativeRisks.at(next.second).at(next.first);

        for (auto& dir : changes) {
            auto n = std::pair<int, int>{next.first + dir.first, next.second + dir.second};
            if (n.first > dest.first || n.first < 0) continue;
            if (n.second > dest.second || n.second < 0) continue;

            auto risk = data.at(n.second).at(n.first);
            auto newRisk = risk + currRisk;
            if (cumulativeRisks.at(n.second).at(n.first) > newRisk) {
                cumulativeRisks.at(n.second).at(n.first) = newRisk;
                toVisit.push(n);
            }
        }
    } while(toVisit.size());
    for (auto& row : cumulativeRisks) {
        for (auto& cell : row) std::cout << std::setw(4) << cell << " ";
        std::cout << std::endl;
    }
    return cumulativeRisks.at(dest.second).at(dest.first);
}

}
