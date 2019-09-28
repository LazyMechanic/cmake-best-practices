#include "test_cmake_library.h"

#include <iostream>

#include <yaml-cpp/yaml.h>

void test_cmake_library::print()
{
    auto doc = YAML::Load(
        "---"
        "Kuku:"
        "  - Epta"
        "...");
    std::cout << "test_cmake_library::print()" << std::endl;
    std::cout << YAML::Dump(doc) << std::endl;
}
