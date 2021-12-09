#include "Day9.hpp"

#include "aoc2021/runners/Runner.hpp"
#include "aoc2021/util/Loader.hpp"

namespace aoc {

Day9::Day9() : mapData(loadType<std::vector<int>>("9",
        [](const std::string& in) {
            std::vector<int> ret;
            for (auto& num : in) {
                ret.push_back(num - '0');
            }
            return ret;
        })) {}

StrPair Day9::run() {
    std::string a, b;

    const auto width = mapData.at(0).size();
    const auto height = mapData.size();

    {
        int risk = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                auto sourceNum = mapData.at(i).at(j);
                risk += ((i != 0 ? mapData.at(i - 1).at(j) > sourceNum : true)
                         && (i != height - 1 ? mapData.at(i + 1).at(j) > sourceNum : true)
                         && (j != 0 ? mapData.at(i).at(j - 1) > sourceNum : true)
                         && (j != width - 1 ? mapData.at(i).at(j + 1) > sourceNum : true)
                        ) ? 1 + sourceNum : 0;
            }
        }
        a = std::to_string(risk);
    }

    return {a, b};
}

}
