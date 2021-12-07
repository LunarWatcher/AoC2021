#include "Runner.hpp"
#include <optional>
#include <vector>
#include <memory>
#include <map>

namespace aoc {

class Day4 : public Runner {
public:
    typedef std::vector<std::vector<std::shared_ptr<std::pair<int, bool>>>> Board;
    typedef std::vector<Board> Boards;
private:
    std::map<int, std::shared_ptr<std::pair<int, bool>>> pool;
    std::vector<int> numbers;
    Boards boards;

private:
    std::optional<Board> checkBingo(const Boards& boards);

public:
    Day4();

    StrPair run() override;

    int sumBoard(const Board& b);
};

}
