///
/// @file Env.hpp
/// @brief This file contains env utility functions
/// @namespace utl
///

#pragma once

#include <string>
#include <vector>

namespace utl
{
    [[nodiscard]] std::vector<std::string> getEnv(const char *const *env);
} // namespace utl
