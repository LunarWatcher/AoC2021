#include "Day12.hpp"
#include "stc/StringUtil.hpp"

#include <queue>
#include <algorithm>

namespace aoc {

Day12::Day12() {
    auto raw = loadFile("12");
    for (auto& line : raw) {
        auto vec = stc::string::split(line, '-');
        auto from = vec.at(0),
             to = vec.at(1);
        if (from == "end" || to == "start") {
            std::string tmp = from;
            from = to;
            to = tmp;
        }
        // The graph isn't directed
        data[from].push_back(to);
        if (to != "end" && from != "start")
            data[to].push_back(from);
    }
    data["end"] = {};
}

int Day12::runPart(bool partB) {

    std::shared_ptr<Node> root = std::make_shared<Node>("start");

    std::queue<std::shared_ptr<Node>> next;
    next.push(root);
    do {
        auto current = next.front();
        next.pop();
        //std::cout << "--- Processing " << current->name << "(parent: " << (current->parent ? current->parent->name : "None") << ")" << std::endl;

        auto children = data.at(current->name);
        for (auto& child : children) {
            bool dupeFlag = false;
            if (child != "end" && std::all_of(child.begin(), child.end(), [](const char& c) {
                        return std::islower(c);
                    }) && findNotContains(current, child)) {
                if (partB && !current->subtreeHasDupes) {
                    dupeFlag = true;
                } else
                    continue;
            }
            //std::cout << "Appending " << child << std::endl;
            auto newNode = std::make_shared<Node>(child);
            newNode->parent = current;
            newNode->subtreeHasDupes = dupeFlag | current->subtreeHasDupes;
            current->children.push_back(newNode);
            if (child != "end")
                next.push(newNode);
        }
    } while (next.size());

    return count(root);
}

StrPair Day12::run() {
    return {std::to_string(runPart()), std::to_string(runPart(true))};
}

}
