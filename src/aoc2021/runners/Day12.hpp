#pragma once

#include "Runner.hpp"

#include <unordered_map>


namespace aoc {

struct Node {
    std::string name;
    bool subtreeHasDupes = false;

    std::shared_ptr<Node> parent;
    Node(std::string name) : name(name) {}
};

class Day12 : public Runner {
private:
    // Glorified linked list
    std::unordered_map<std::string, std::vector<std::string>> data;

    bool findNotContains(std::shared_ptr<Node> tree, const std::string& search) {
        while (tree != nullptr && tree->parent != nullptr) {
            if (tree->name == search) return true;
            tree = tree->parent;
        }
        return false;
    }

    int runPart(bool partB = false);
public:
    Day12();

    StrPair run() override;
    

};

}
