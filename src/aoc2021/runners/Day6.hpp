#include "Runner.hpp"

#include "aoc2021/util/Loader.hpp"
#include <map>

namespace aoc {

class Day6 : public Runner {
private:
    std::vector<int> rawData;
    std::map<int, long long> states;
    int executed = 0;
public:
    Day6();

    long long simulate(int days);

    std::string part1() override;
    std::string part2() override;
};

}
