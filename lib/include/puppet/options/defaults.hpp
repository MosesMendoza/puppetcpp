/**
 * @file
 * Declares the default options.
 */
#pragma once

#include <string>
#include <vector>

namespace puppet { namespace options {

    /**
     * Represents platform-specific option defaults.
     */
    struct defaults
    {
        /**
         * Gets the default code directory for the current platform.
         * @return Returns the default code directory.
         */
        static std::string code_directory();

        /**
         * Gets the default environment path for the current platform.
         * @return Returns the default environment path.
         */
        static std::string environment_path();

        /**
         * Gets the default global module directories for the current platform.
         * @return Returns the default global modules directories.
         */
        static std::vector<std::string> module_directories();
    };

}}  // namespace puppet::options
