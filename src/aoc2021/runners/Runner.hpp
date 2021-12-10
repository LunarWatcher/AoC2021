#pragma once

#include <string>

#include "aoc2021/util/Loader.hpp"

namespace aoc {

typedef std::pair<std::string, std::string> StrPair;
class Runner {
public:
    virtual StrPair run() = 0;
};

}
