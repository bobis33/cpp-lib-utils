///
/// @file IPlugin.hpp
/// @brief This file contains the plugin interface
/// @namespace utl
///

#pragma once

#include <string>

namespace utl
{

    ///
    /// @interface IPlugin
    /// @brief Interface for plugins
    /// @namespace utl
    ///
    class IPlugin
    {

        public:
            virtual ~IPlugin() = default;

            [[nodiscard]] virtual const std::string getName() const = 0;
    }; // interface IPlugin
} // namespace utl
