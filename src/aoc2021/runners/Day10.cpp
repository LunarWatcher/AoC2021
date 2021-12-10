#include "Day10.hpp"

#include <cmath>
#include <map>
#include <stack>

namespace aoc {

Day10::Day10() : data(loadFile("10")) {}
 
StrPair Day10::run() {
    std::map<char, int> score = {
        {')', 3},
        {']', 57},
        {'}', 1197},
        {'>', 25137}
    };
    std::map<char, int> completionScore = {
        {')', 1},
        {']', 2},
        {'}', 3},
        {'>', 4}
    };

    long long resultA = 0;
    std::vector<long long> resultB;

    for (auto& line : data) {
        std::stack<char> q;
        for (auto& chr : line) {
            if (!score.contains(chr)) {
                q.push(chr);
            } else {
                char toClose = q.top();
                q.pop();
                if (chr != pairMaps.at(toClose)) {
                    resultA += score.at(chr);
                    goto continueOuter;
                }
            }
        }
        {
            long long score = 0;
            // Line is clean
            while (!q.empty()) {
                char c = q.top();
                q.pop();
                
                char next = pairMaps.at(c);
                score *= 5;
                score += completionScore.at(next);
            }
            resultB.push_back(score);
        }
continueOuter: continue;
    }

    std::sort(resultB.begin(), resultB.end());
    return {
        std::to_string(resultA),
        std::to_string(resultB.at(std::floor(resultB.size() / 2.0)))
    };
}

}
