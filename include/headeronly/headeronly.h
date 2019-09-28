#pragma once

#include <iostream>

#include <yaml-cpp/yaml.h>

class cmake_best_practice_headeronly {
public:
    void print();
};

inline void cmake_best_practice_headeronly::print()
{
    auto doc = YAML::Load(
        "---"
        "First:"
        "  - First_second"
        "...");
    std::cout << "cmake_best_practice_headeronly::print()" << std::endl;
    std::cout << YAML::Dump(doc) << std::endl;
}
