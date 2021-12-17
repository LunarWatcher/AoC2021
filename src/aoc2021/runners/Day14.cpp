#include "Day14.hpp"
#include "aoc2021/util/Loader.hpp"
#include "stc/StringUtil.hpp"

namespace aoc {

Day14::Day14() {
    auto lines = loadFile("14");

    this->pairs = lines.at(0);
    for (int i = 2; i < lines.size(); ++i) {
        auto split = stc::string::split(lines.at(i), " -> ");
        std::cout << split.at(0) << split.at(1);
        mapping[split.at(0)] = split.at(1);
    }
}

StrPair Day14::run() {
    return {"", ""};
}

}
