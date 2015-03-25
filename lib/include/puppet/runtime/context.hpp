/**
 * @file
 * Declares the runtime evaluation context.
 */
#pragma once

#include "scope.hpp"
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>

namespace puppet { namespace runtime {

    /**
     * Represents the runtime evaluation context.
     */
    struct context
    {
        /**
         * Constructs an evaluation context.
         */
        context();

        /**
         * Pushes a new scope onto the evaluation context.
         * @param name The name of the scope.
         * @param parent_name The name of the scope's parent scope.
         * @return Returns true if the scope was pushed or false if not (scope with the given name already exists).
         */
        bool push(std::string name = std::string(), std::string const& parent_name = std::string());

        /**
         * Pops the current scope.
         * @return Returns true if the scope was popped or false if not (already at top scope).
         */
        bool pop();

        /**
         * Lookup a variable by name.
         * @name The name of the variable to lookup.
         * @return Returns the value of the variable or nullptr if the variable is not defined.
         */
        value const* lookup(std::string const& name) const;

        /**
         * Gets the current scope.
         * @return Returns the current scope.
         */
        scope const& current() const;

        /**
         * Gets the current scope.
         * @return Returns the current scope.
         */
        scope& current();

    private:
        std::unordered_map<std::string, std::shared_ptr<scope>> _scopes;
        std::stack<std::shared_ptr<scope>> _stack;
        std::shared_ptr<scope> _top;
    };

}}  // puppet::runtime