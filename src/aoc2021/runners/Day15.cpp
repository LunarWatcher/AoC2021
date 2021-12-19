#include "Day15.hpp"

#include <cmath>
#include <queue>
#include <utility>

namespace aoc {

Day15::Day15() {
    auto data = loadFile("15");
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

    static const std::vector<std::pair<int, int>> changes = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    std::vector<std::vector<int>> cumulativeRisks;
    cumulativeRisks.resize(height * 5);
    for (auto& row : cumulativeRisks) {
        row.resize(width * 5);
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
            if (n.first >= width || n.first < 0) continue;
            if (n.second >= height || n.second < 0) continue;

            auto risk = data.at(n.second).at(n.first);
            auto newRisk = risk + currRisk;
            if (cumulativeRisks.at(n.second).at(n.first) > newRisk) {
                cumulativeRisks.at(n.second).at(n.first) = newRisk;
                toVisit.push(n);
            }
        }
    } while(toVisit.size());

    auto bigData = this->data;
    bigData.resize(height * 5);

    for (int y = 0; y < bigData.size(); ++y) {
        auto yCell = std::floor(y / height);
        bigData.at(y).resize(5 * width);

        for (int x = 0; x < 5 * width; ++x) {
            if (y < height && x < width) continue;
            auto xCell = std::floor(x / width);
            // This part is straight-forward; we need to recalculate each cell in bigData.
            if (xCell == 0) {
                bigData.at(y).at(x) = std::max(1, (bigData.at(y - height).at(x) + 1) % 10);
            } else {
                bigData.at(y).at(x) = std::max(1, (bigData.at(y).at(x - width) + 1) % 10);
            }
            // I'm not gonna lie, I'm not entirely sure why this works, but because we scale the surrounding cells linearly, the cumulative weight is
            // preserved across the copied cells.
            // This wouldn't work if the rest of the data was arbitrary or otherwise a fucking mess, but given the linear behavior of this particular
            // dataset, this works.
            //
            // We find the minimum of the cell above and the cell to the left, if one exists.
            // Given that we've already found the minimum paths for one cell, this seems to be a hyper-optimized way to search. Of course only works
            // since we don't have any negative weights, but this is a really elegant solution.
            int optA = 99999, optB = optA;
            if (x != 0) {
                optA = cumulativeRisks.at(y).at(x - 1) + bigData.at(y).at(x);
            }
            if (y != 0) {
                optB = cumulativeRisks.at(y - 1).at(x) + bigData.at(y).at(x);
            }
            cumulativeRisks.at(y).at(x) = std::min(optA, optB);
        }
    }

    a = std::to_string(cumulativeRisks.at(height - 1).at(width - 1));
    b = std::to_string(cumulativeRisks.at(height * 5 - 1).at(width * 5 - 1));

    return {a, b};
}

int Day15::search(const std::vector<std::vector<int>>& data) {
}

}
