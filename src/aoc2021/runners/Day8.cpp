#include "Day8.hpp"

#include "aoc2021/util/Loader.hpp"
#include "stc/StringUtil.hpp"

#include <algorithm>
#include <map>

namespace aoc {

Day8::Day8() : data(loadType<InOutPair>("8",
        [](const std::string& line) -> InOutPair {
            auto split = stc::string::split(line, " | ");

            auto in = convertStringToVec<std::string>(split.at(0), ' ', nullptr);
            auto out = convertStringToVec<std::string>(split.at(1), ' ', nullptr);
            for (auto& item : in) {
                std::sort(item.begin(), item.end());
            }
            for (auto& item : out) {
                std::sort(item.begin(), item.end());
            }
            return { in, out };
        })) {
}

StrPair Day8::run() {
    std::string a, b = "TODO";
    {
        long sum = 0;
        // Looking for 1, 4, 7, 8
        for (auto& [_, output] : data) {
            for (auto& digit : output) {
                if (digit.size() == 2 || digit.size() == 3 || digit.size() == 4 || digit.size() == 7) {
                    ++sum;
                }
            }
        }
        a = std::to_string(sum);
    }
    {

        std::map<std::string, std::string> map = {
            {"abcdef", "9"},
            {"abcdefg", "8"},
            {"abd", "7"},
            {"bcdefg", "6"},
            {"bcdef", "5"},
            {"abef", "4"},
            {"abcdf", "3"},
            {"acdfg", "2"},
            {"ab", "1"},
            {"abcdeg", "0"}
        };
        //long long sum = 0;
        //for (auto& [_, output] : data) {
            //std::string num;
            //for (auto& c : output) {
                //std::cout << c << std::endl;
                //num += map.at(c);
            //}
            //sum += std::stoi(num);
        //}
        //b = std::to_string(sum);
    }

    return {
        a, b
    };
}

}
