#pragma once

#include "Runner.hpp"

#include <map>

namespace aoc {

struct Node {
    std::string name;
    std::vector<std::shared_ptr<Node>> children;
    bool subtreeHasDupes = false;

    std::shared_ptr<Node> parent;
    Node(std::string name) : name(name) {}
};

class Day12 : public Runner {
private:
    // Glorified linked list
    std::map<std::string, std::vector<std::string>> data;

    bool findNotContains(std::shared_ptr<Node> tree, const std::string& search) {
        if (tree->name == search) return true;
        if (tree == nullptr || tree->parent == nullptr) return false;
        return findNotContains(tree->parent, search);
    }

    int count(std::shared_ptr<Node> node) {
        if (node->name != "end") {
            int sum = 0;
            for (auto& child : node->children) {
                sum += count(child);
            }
            return sum;
        } else {
            return 1;
        }
    }

    int runPart(bool partB = false);
public:
    Day12();

    StrPair run() override;
    

};

}
