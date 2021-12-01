#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>

namespace aoc {

inline int sastoi(const std::string& input) { return std::stoi(input); }
inline long long sastoll(const std::string& input) { return std::stoll(input); }

inline std::vector<int> convertStringToIntVec(const std::string& input, char delimiter) {
    std::vector<int> vec;
    std::stringstream ss(input);
    std::string tmp;
    while (std::getline(ss, tmp, ',')) {
        vec.push_back(std::stoi(tmp));
    }
    return vec;
}

inline std::vector<std::string> loadFile(int day) {
    std::ifstream stream("input/day" + std::to_string(day) + ".txt");
    if (!stream) {
        std::cout << "File not found for day " << day << std::endl;
        throw "File not found for day " + std::to_string(day);
    }
    std::vector<std::string> str;
    std::string tmp;

    while (std::getline(stream, tmp)) {
        str.push_back(tmp);
    }
    return str;
}

template <typename T>
inline std::vector<T> loadType(int day, std::function<T(const std::string&)> converter) {
    auto rawFile = loadFile(day); 
    std::vector<T> vec;

    for (auto& tmp : rawFile) {
        vec.push_back(converter(tmp));
    }
    return vec;
}

}
