///
/// @file IPlugin.hpp
/// @brief This file contains the plugin interface
/// @namespace utl
///

#pragma once

#include <string>

namespace utl
{

    enum PluginType : uint8_t
    {
        AUDIO = 0,
        NETWORK = 1,
        RENDERER = 2,
        WINDOW = 3,
        UNDEFINED = 255,
    };

    ///
    /// @interface IPlugin
    /// @brief Interface for plugins
    /// @namespace utl
    ///
    class IPlugin
    {

        public:
            virtual ~IPlugin() = default;

            [[nodiscard]] virtual std::string getName() const = 0;
            [[nodiscard]] virtual PluginType getType() const = 0;

    }; // interface IPlugin
} // namespace utl
