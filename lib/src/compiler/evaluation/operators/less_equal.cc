#include <puppet/compiler/evaluation/operators/less_equal.hpp>
#include <puppet/compiler/exceptions.hpp>
#include <boost/format.hpp>

using namespace std;
using namespace puppet::runtime;
using namespace puppet::runtime::values;

namespace puppet { namespace compiler { namespace evaluation { namespace operators {

    struct less_equal_visitor : boost::static_visitor<value>
    {
        explicit less_equal_visitor(binary_operator_context const& context) :
            _context(context)
        {
        }

        result_type operator()(int64_t left, int64_t right) const
        {
            return left <= right;
        }

        result_type operator()(int64_t left, double right) const
        {
            return operator()(static_cast<double>(left), right);
        }

        result_type operator()(double left, int64_t right) const
        {
            return operator()(left, static_cast<double>(right));
        }

        result_type operator()(double left, double right) const
        {
            return left <= right;
        }

        result_type operator()(string const& left, string const& right) const
        {
            // TODO: revisit performance
            return boost::ilexicographical_compare(left, right) || boost::iequals(left, right);
        }

        result_type operator()(type const& left, type const& right) const
        {
            return left == right || left.is_specialization(right);
        }

        template <
            typename Right,
            typename = typename enable_if<!is_same<Right, int64_t>::value>::type,
            typename = typename enable_if<!is_same<Right, double>::value>::type
        >
        result_type operator()(int64_t const&, Right const& right) const
        {
            throw evaluation_exception((boost::format("expected %1% for comparison but found %2%.") % types::numeric::name() % value(right).get_type()).str(), _context.right_context());
        }

        template <
            typename Right,
            typename = typename enable_if<!is_same<Right, int64_t>::value>::type,
            typename = typename enable_if<!is_same<Right, double>::value>::type
        >
        result_type operator()(double const&, Right const& right) const
        {
            throw evaluation_exception((boost::format("expected %1% for comparison but found %2%.") % types::numeric::name() % value(right).get_type()).str(), _context.right_context());
        }

        template <
            typename Right,
            typename = typename enable_if<!is_same<Right, string>::value>::type
        >
        result_type operator()(string const&, Right const& right) const
        {
            throw evaluation_exception((boost::format("expected %1% for comparison but found %2%.") % types::string::name() % value(right).get_type()).str(), _context.right_context());
        }

        template <
            typename Right,
            typename = typename enable_if<!is_same<Right, type>::value>::type
        >
        result_type operator()(type const&, Right const& right) const
        {
            throw evaluation_exception((boost::format("expected %1% for comparison but found %2%.") % types::type::name() % value(right).get_type()).str(), _context.right_context());
        }

        template <typename Left, typename Right>
        result_type operator()(Left const& left, Right const&) const
        {
            throw evaluation_exception((boost::format("expected %1%, %2%, or %3% for comparison but found %4%.") % types::numeric::name() % types::string::name() % types::type::name() % value(left).get_type()).str(), _context.left_context());
        }

     private:
        binary_operator_context const& _context;
    };

    value less_equal::operator()(binary_operator_context const& context) const
    {
        return boost::apply_visitor(less_equal_visitor(context), context.left(), context.right());
    }

}}}}  // namespace puppet::compiler::evaluation::operators
