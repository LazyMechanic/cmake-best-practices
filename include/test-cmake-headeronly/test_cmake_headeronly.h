#pragma once

#include <yaml-cpp/yaml.h>
#include <iostream>

class test_cmake_headeronly {
public:
    void print();
};

inline void test_cmake_headeronly::print()
{
    auto doc = YAML::Load(
        "---"
        "Kuku:"
        "  - Epta"
        "...");
    std::cout << "test_cmake_headeronly::print()" << std::endl;
    std::cout << YAML::Dump(doc) << std::endl;
}
