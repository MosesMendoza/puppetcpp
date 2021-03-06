/**
 * @file
 * Declares the "runtime" type.
 */
#pragma once

#include "../values/forward.hpp"
#include <boost/variant.hpp>
#include <boost/optional.hpp>
#include <ostream>

namespace puppet { namespace compiler { namespace evaluation { namespace collectors {

    // Forward declaration of collector.
    struct collector;

}}}}  // namespace puppet::compiler::evaluation::collectors

namespace puppet { namespace runtime { namespace types {

    // Forward declaration of recursion_guard
    struct recursion_guard;

    /**
     * Represents the Puppet Runtime type.
     * This type represents an object in the runtime that is not part of the Puppet type system.
     */
    struct runtime
    {
        /**
         * The type of associated object.
         */
        using object_type =
            boost::variant<
                std::shared_ptr<compiler::evaluation::collectors::collector>
            >;

        /**
         * Constructs a Runtime type.
         * @param runtime_name The name of the runtime (e.g. C++).
         * @param type_name The name of the type (e.g. Collector).
         */
        explicit runtime(std::string runtime_name = {}, std::string type_name = {});

        /**
         * Constructs a Runtime type.
         * @param object The runtime object associated with this type.
         */
        explicit runtime(boost::optional<object_type> object);

        /**
         * Gets the runtime name.
         * @return Returns the runtime name.
         */
        std::string const& runtime_name() const;

        /**
         * Gets the type name.
         * @return Returns the type name.
         */
        std::string const& type_name() const;

        /**
         * Gets the associated object.
         * @return Returns the associated object.
         */
        boost::optional<object_type> const& object() const;

        /**
         * Gets the name of the type.
         * @return Returns the name of the type (i.e. Runtime).
         */
        static char const* name();

        /**
         * Creates a generalized version of the type.
         * @return Returns the generalized type.
         */
        values::type generalize() const;

        /**
         * Determines if the given value is an instance of this type.
         * @param value The value to determine if it is an instance of this type.
         * @param guard The recursion guard to use for aliases.
         * @return Returns true if the given value is an instance of this type or false if not.
         */
        bool is_instance(values::value const& value, recursion_guard& guard) const;

        /**
         * Determines if the given type is assignable to this type.
         * @param other The other type to check for assignability.
         * @param guard The recursion guard to use for aliases.
         * @return Returns true if the given type is assignable to this type or false if the given type is not assignable to this type.
         */
        bool is_assignable(values::type const& other, recursion_guard& guard) const;

        /**
         * Writes a representation of the type to the given stream.
         * @param stream The stream to write to.
         * @param expand True to specify that type aliases should be expanded or false if not.
         */
        void write(std::ostream& stream, bool expand = true) const;

     private:
        std::string _runtime_name;
        std::string _type_name;
        boost::optional<object_type> _object;
    };

    /**
     * Stream insertion operator for Runtime type.
     * @param os The output stream to write the type to.
     * @param type The Runtime type to write.
     * @return Returns the given output stream.
     */
    std::ostream& operator<<(std::ostream& os, runtime const& type);

    /**
     * Equality operator for runtime.
     * @param left The left type to compare.
     * @param right The right type to compare.
     * @return Returns true if the two types are equal or false if not.
     */
    bool operator==(runtime const& left, runtime const& right);

    /**
     * Inequality operator for runtime.
     * @param left The left type to compare.
     * @param right The right type to compare.
     * @return Returns true if the two types are not equal or false if they are equal.
     */
    bool operator!=(runtime const& left, runtime const& right);

    /**
     * Hashes the runtime type.
     * @param type The runtime type to hash.
     * @return Returns the hash value for the type.
     */
    size_t hash_value(runtime const& type);

}}}  // namespace puppet::runtime::types
