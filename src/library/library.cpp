#include "cmake_best_practice_library.h"

#include <iostream>

#include <yaml-cpp/yaml.h>

void cmake_best_practice_library::print()
{
    auto doc = YAML::Load(
        "---"
        "First:"
        "  - First_second"
        "...");
    std::cout << "cmake_best_practice_library::print()" << std::endl;
    std::cout << YAML::Dump(doc) << std::endl;
}
