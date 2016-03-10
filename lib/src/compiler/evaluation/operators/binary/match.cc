#include <puppet/compiler/evaluation/operators/binary/match.hpp>
#include <puppet/compiler/evaluation/operators/binary/call_context.hpp>
#include <puppet/compiler/exceptions.hpp>
#include <boost/format.hpp>

using namespace std;
using namespace puppet::runtime;

namespace puppet { namespace compiler { namespace evaluation { namespace operators { namespace binary {

    bool is_match(call_context& context, string const& left, string const& right)
    {
        auto& evaluation_context = context.context();

        try {
            smatch matches;
            bool result = right.empty() || regex_search(left, matches, std::regex(right));
            evaluation_context.set(matches);
            return result;
        } catch (regex_error const& ex) {
            throw evaluation_exception(
                (boost::format("invalid regular expression: %1%") %
                 ex.what()
                ).str(),
                context.right_context(),
                evaluation_context.backtrace()
            );
        }
    }

    bool is_match(call_context& context, string const& left, values::regex const& right)
    {
        smatch matches;
        bool result = right.pattern().empty() || regex_search(left, matches, right.value());
        context.context().set(matches);
        return result;
    }

    descriptor match::create_descriptor()
    {
        binary::descriptor descriptor{ ast::binary_operator::match };

        descriptor.add("String", "String", [](call_context& context) {
            return is_match(context, context.left().require<string>(), context.right().require<string>());
        });
        descriptor.add("String", "Regexp", [](call_context& context) {
            return is_match(context, context.left().require<string>(), context.right().require<values::regex>());
        });
        descriptor.add("Any", "Type", [](call_context& context) {
            return context.right().require<values::type>().is_instance(context.left());
        });
        return descriptor;
    }

}}}}}  // namespace puppet::compiler::evaluation::operators::binary
