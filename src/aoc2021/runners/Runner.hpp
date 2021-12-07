#pragma once

#include <string>

namespace aoc {

typedef std::pair<std::string, std::string> StrPair;
class Runner {
public:
    virtual StrPair run() = 0;
};

}
