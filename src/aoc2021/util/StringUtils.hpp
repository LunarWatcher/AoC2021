// NOTE: This file is effectively a staging file for stc, and will be removed
// once I've merged it into stc.
#pragma once

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

namespace stc {

namespace string {

inline std::vector<std::string> splitString(const std::string& input, const char delimiter, int limit = -1) {
    if (delimiter == 0) {
        std::vector<std::string> out;
        std::transform(input.begin(), input.end(), std::back_inserter(out), [](const char& chr) {
            return std::string(1, chr);
        });
        return std::move(out);
    } else if (limit == 0) {
        return {input};
    }

    std::vector<std::string> out;
    std::stringstream stream(input);
    std::string line;
    int count = 0;
    while (getline(stream, line, delimiter)) {
        out.push_back(line);
        // TODO: add limit
        //if (limit != -1) {
            //++count;
            //if (count == limit) {
                //break;
            //}
        //}
    }

    return out;
}


inline std::vector<std::string> splitString(const std::string& input, const std::string& delimiter, int limit = -1) {
    if (delimiter.size() <= 1) {
        return splitString(input, 0, limit);
    } else if (limit == 0) {
        return {input};
    }

    std::vector<std::string> out;
    size_t pos = 0, index = 0;
    std::string token;
    int count = 0;
    while ((pos = input.find(delimiter, index)) != std::string::npos) {
        token = input.substr(0, pos);
        index = pos + delimiter.size();
        out.push_back(token);
        count++;
        if (count == limit) {
            break;
        }
    }
    if (index < input.size() - 1) {
        out.push_back(input.substr(index));
    }
    return out;

}

}

}
