#include "Day12.hpp"
#include "stc/StringUtil.hpp"

#include <queue>
#include <stack>
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
    int cnt = 0;


    std::vector<std::shared_ptr<Node>> next;
    {
        std::shared_ptr<Node> root = std::make_shared<Node>("start");
        next.push_back(root);
    }
    do {
        auto current = next.back();
        next.pop_back();

        auto children = data.at(current->name);
        for (auto& child : children) {
            bool dupeFlag = false;
            if (child != "end" && std::all_of(child.begin(), child.end(), [](const char& c) {
                        return c >= 'a';
                    }) && findNotContains(current, child)) {
                if (partB && !current->subtreeHasDupes) {
                    dupeFlag = true;
                } else
                    continue;
            }
            auto newNode = std::make_shared<Node>(child);
            newNode->parent = current;
            newNode->subtreeHasDupes = dupeFlag | current->subtreeHasDupes;
            if (child != "end")
                next.push_back(newNode);
            else
                ++cnt;
        }
    } while (next.size());

    return cnt;
}

StrPair Day12::run() {
    return {std::to_string(runPart()), std::to_string(runPart(true))};
}

}
