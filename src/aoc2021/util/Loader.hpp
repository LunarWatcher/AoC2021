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

template <typename T>
inline std::vector<T> convertStringToVec(const std::string& input, char delimiter, std::function<T(const std::string&)> converter) {
    std::vector<T> vec;
    std::stringstream ss(input);
    std::string tmp;
    while (std::getline(ss, tmp, delimiter)) {
        vec.push_back(converter ? converter(tmp) : tmp);
    }
    return vec;

}

inline std::vector<std::string> loadFile(std::string day) {
    std::ifstream stream("input/day" + day + ".txt");
    if (!stream) {
        std::cout << "File not found for day " << day << std::endl;
        throw "File not found for day " + day;
    }
    std::vector<std::string> str;
    std::string tmp;

    while (std::getline(stream, tmp)) {
        str.push_back(tmp);
    }
    return str;
}

template <typename T>
inline std::vector<T> loadType(std::string day, std::function<T(const std::string&)> converter) {
    auto rawFile = loadFile(day);
    std::vector<T> vec;
    std::transform(rawFile.begin(), rawFile.end(), std::back_inserter(vec), converter);
    return vec;
}

}
