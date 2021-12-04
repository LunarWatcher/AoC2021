#include "Day4.hpp"

#include "aoc2021/util/Loader.hpp"
#include <sstream>

namespace aoc {

Day4::Day4() {
    auto content = loadFile("4" /*"-test"/**/);

    std::stringstream ss(content.at(0));
    std::string line;
    while (std::getline(ss, line, ',')) {
        numbers.push_back(std::stoi(line));
    }
    Board currBoard;

    for (int i = 2; i < content.size(); ++i) {
        std::vector<std::shared_ptr<std::pair<int, bool>>> currLine;
        std::string line = content.at(i);
        if (line == "") {
            boards.push_back(currBoard);
            currBoard.clear();
            continue;
        }
        std::stringstream ss(content.at(i));
        int num;
        while (ss >> num) {
            if (pool[num] == nullptr) {
                pool[num] = std::make_shared<std::pair<int, bool>>(num, false);
            }
            currLine.push_back(pool[num]);
        }
        currBoard.push_back(currLine);
    }
    boards.push_back(currBoard);
}

std::optional<Day4::Board> Day4::checkBingo(const Day4::Boards& boards) {
    for (const Board& board : boards) {
        // Check rows
        for (auto& row : board) {
            
            bool bingo = true;
            for (auto& num : row) {
                bingo &= num->second;
            }
            if (bingo) {
                return board;
            }
        }
        // iterate cols
        for (int i = 0; i < board.size(); ++i) {
            bool bingo = true;
            // Iterate rows
            for (int j = 0; j < board.size(); ++j) {
                bingo &= board.at(j).at(i)->second;
            }
            if (bingo) return board;
        }
    }
    return {};
}

std::string Day4::part1() {
    for (auto number : numbers) {
        pool[number]->second = true;
    
        std::optional<Board> winner = checkBingo(boards);
        if (winner) {
            return std::to_string(sumBoard(*winner) * number);
        }
    }
    return "Failed to find answer";
}
std::string Day4::part2() {
    for (auto number : numbers) {
        pool[number]->second = true;
    
        while (std::optional<Board> winner = checkBingo(boards)) {
            if (boards.size() == 1) {
                return std::to_string(sumBoard(*winner) * number);
            } else {
                boards.erase(std::find(boards.begin(), boards.end(), winner));
            }
        }

    }
    return "Failed to find answer";
}

int Day4::sumBoard(const Board& b) {
    int sum = 0;
    for (auto& row : b) {
        for (auto& num : row) {
            if (!num->second) {
                sum += num->first;
            }
        }
    }
    return sum;
}

}
