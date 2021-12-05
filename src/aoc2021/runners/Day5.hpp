#include "Runner.hpp"
#include "aoc2021/util/Loader.hpp"

#include <utility>
#include <vector>
#include <map>

namespace aoc {

class Day5 : public Runner {
public:
    typedef std::pair<int, int> Point;
    typedef std::pair<Point, Point> Line;
private:
    std::map<std::pair<int, int>, int> map;
    std::vector<Line> lines;
    std::tuple<int, int> minMax(int a, int b) {
        if (a < b) {
            return {a, b};
        }
        return {b, a};
    }
public:
    Day5();

    std::string part1() override;
    std::string part2() override;
};

}
