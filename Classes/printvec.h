
#ifndef OOP_PRINTVEC_H
#define OOP_PRINTVEC_H

#include <iostream>
#include <vector>
#include <unordered_map>

template<typename T>
void printVec(std::vector<T> x) {
    for (auto &t: x) {
        std::cout << t;
    }
}

template<typename T, typename V>
void printMap(std::unordered_map<V, T> x) {
    for (auto &t: x) {
        std::cout << t.second;
    }
}

#endif
