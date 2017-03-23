/**
 * @file
 * Declares Boost Spirit parsing rules.
 */
#pragma once

#include "parsers.hpp"
#include "../ast/adapted.hpp"

namespace puppet { namespace compiler { namespace parser {

/**
 * Macro for declaring a parser rule.
 * @param name The name of the rule.
 * @param description The rule description.
 * @param ... The AST type generated by the rule.
 */
#define DECLARE_RULE(name, description, ...) boost::spirit::x3::rule<class name##_tag, __VA_ARGS__> const name = description;
/**
 * Macro for defining a rule.
 * @param name The rule name.
 * @param rule The rule definition.
 */
#define DEFINE_RULE(name, rule) auto const name##_def = rule;

    /// @cond NOT_DOCUMENTED

    // Basic expression rules
    DECLARE_RULE(basic_expression,                "expression",                      ast::basic_expression)
    DECLARE_RULE(undef,                           "undef",                           ast::undef)
    DECLARE_RULE(defaulted,                       "default",                         ast::defaulted)
    DECLARE_RULE(boolean,                         "boolean",                         ast::boolean)
    DECLARE_RULE(number,                          "number",                          ast::number)
    DECLARE_RULE(string,                          "string",                          ast::string)
    DECLARE_RULE(regex,                           "regex",                           ast::regex)
    DECLARE_RULE(variable,                        "variable",                        ast::variable)
    DECLARE_RULE(name,                            "name",                            ast::name)
    DECLARE_RULE(bare_word,                       "bare word",                       ast::bare_word)
    DECLARE_RULE(type,                            "type",                            ast::type)
    DECLARE_RULE(interpolated_string,             "string",                          ast::interpolated_string)
    DECLARE_RULE(interpolated_string_part,        "string part",                     ast::interpolated_string_part)
    DECLARE_RULE(literal_string_text,             "string text",                     ast::literal_string_text)
    DECLARE_RULE(array,                           "array",                           ast::array)
    DECLARE_RULE(hash,                            "hash",                            ast::hash)
    DECLARE_RULE(pairs,                           "pairs",                           std::vector<ast::pair>)
    DECLARE_RULE(pair,                            "pair",                            ast::pair)
    DECLARE_RULE(case_expression,                 "case expression",                 ast::case_expression)
    DECLARE_RULE(proposition,                     "proposition",                     ast::proposition)
    DECLARE_RULE(if_expression,                   "if expression",                   ast::if_expression)
    DECLARE_RULE(elsif,                           "elsif",                           ast::elsif)
    DECLARE_RULE(else_,                           "else",                            ast::else_)
    DECLARE_RULE(unless_expression,               "unless expression",               ast::unless_expression)
    DECLARE_RULE(function_call_expression,        "function call expression",        ast::function_call_expression)
    DECLARE_RULE(function_name,                   "function name",                   ast::name)
    DECLARE_RULE(lambda_expression,               "lambda expression",               ast::lambda_expression)
    DECLARE_RULE(parameters,                      "parameters",                      std::vector<ast::parameter>)
    DECLARE_RULE(parameter,                       "parameter",                       ast::parameter)
    DECLARE_RULE(type_expression,                 "type expression",                 ast::postfix_expression)
    DECLARE_RULE(new_expression,                  "new expression",                  ast::new_expression)
    DECLARE_RULE(epp_render_expression,           "render expression",               ast::epp_render_expression)
    DECLARE_RULE(epp_render_block,                "render block",                    ast::epp_render_block)
    DECLARE_RULE(epp_render_string,               "render string",                   ast::epp_render_string)
    DECLARE_RULE(unary_expression,                "unary expression",                ast::unary_expression)
    DECLARE_RULE(unary_operator,                  "unary operator",                  ast::unary_operator)
    DECLARE_RULE(nested_expression,               "nested expression",               ast::nested_expression)

    // Postfix expression rules
    DECLARE_RULE(postfix_expression,              "expression",                      ast::postfix_expression)
    DECLARE_RULE(postfix_operation,               "postfix operation",               ast::postfix_operation)
    DECLARE_RULE(selector_expression,             "selector expression",             ast::selector_expression)
    DECLARE_RULE(access_expression,               "access expression",               ast::access_expression)
    DECLARE_RULE(method_call_expression,          "method call expression",          ast::method_call_expression)

    // Expression rules
    DECLARE_RULE(expressions,                     "expressions",                     std::vector<ast::expression>)
    DECLARE_RULE(expression,                      "expression",                      ast::expression)
    DECLARE_RULE(binary_operation,                "binary operation",                ast::binary_operation)
    DECLARE_RULE(binary_operator,                 "binary operator",                 ast::binary_operator)

    // Statement rules
    DECLARE_RULE(statements,                      "statements",                      std::vector<ast::statement>)
    DECLARE_RULE(statement,                       "statement",                       ast::statement)
    DECLARE_RULE(class_statement,                 "class statement",                 ast::class_statement)
    DECLARE_RULE(defined_type_statement,          "defined type statement",          ast::defined_type_statement)
    DECLARE_RULE(node_statement,                  "node statement",                  ast::node_statement)
    DECLARE_RULE(hostnames,                       "hostnames",                       std::vector<ast::hostname>)
    DECLARE_RULE(hostname,                        "hostname",                        ast::hostname)
    DECLARE_RULE(function_statement,              "function statement",              ast::function_statement)
    DECLARE_RULE(produces_statement,              "produces statement",              ast::produces_statement)
    DECLARE_RULE(consumes_statement,              "consumes statement",              ast::consumes_statement)
    DECLARE_RULE(application_statement,           "application statement",           ast::application_statement)
    DECLARE_RULE(site_statement,                  "site statement",                  ast::site_statement)
    DECLARE_RULE(type_alias_statement,            "type alias statement",            ast::type_alias_statement)
    DECLARE_RULE(function_call_statement,         "function call statement",         ast::function_call_statement)
    DECLARE_RULE(statement_call_name,             "name",                            ast::name)
    DECLARE_RULE(relationship_statement,          "relationship statement",          ast::relationship_statement)
    DECLARE_RULE(relationship_expression,         "relationship expression",         ast::relationship_expression)
    DECLARE_RULE(relationship_operation,          "relationship operation",          ast::relationship_operation)
    DECLARE_RULE(relationship_operator,           "relationship operator",           ast::relationship_operator)
    DECLARE_RULE(resource_declaration_expression, "resource declaration expression", ast::resource_declaration_expression)
    DECLARE_RULE(resource_type,                   "resource type",                   ast::postfix_expression)
    DECLARE_RULE(class_name,                      "name",                            ast::name)
    DECLARE_RULE(resource_bodies,                 "resource bodies",                 std::vector<ast::resource_body>)
    DECLARE_RULE(resource_body,                   "resource body",                   ast::resource_body)
    DECLARE_RULE(attributes,                      "attributes",                      std::vector<ast::attribute_operation>)
    DECLARE_RULE(attribute,                       "attribute",                       ast::attribute_operation)
    DECLARE_RULE(attribute_name,                  "attribute name",                  ast::name)
    DECLARE_RULE(keyword_name,                    "name",                            ast::name)
    DECLARE_RULE(resource_override_expression,    "resource override expression",    ast::resource_override_expression)
    DECLARE_RULE(resource_override_reference,     "resource override reference",     ast::resource_override_reference)
    DECLARE_RULE(resource_reference,              "resource reference",              ast::postfix_expression)
    DECLARE_RULE(attribute_override,              "attribute",                       ast::attribute_operation)
    DECLARE_RULE(resource_defaults_expression,    "resource defaults expression",    ast::resource_defaults_expression)
    DECLARE_RULE(collector_expression,            "resource collector",              ast::collector_expression)
    DECLARE_RULE(query_expression,                "query expression",                ast::query_expression)
    DECLARE_RULE(basic_query_expression,          "query expression",                ast::basic_query_expression)
    DECLARE_RULE(nested_query_expression,         "nested query expression",         ast::nested_query_expression)
    DECLARE_RULE(attribute_query,                 "attribute query",                 ast::attribute_query)
    DECLARE_RULE(query_operator,                  "query operator",                  ast::query_operator)
    DECLARE_RULE(attribute_query_value,           "attribute value",                 ast::basic_expression)
    DECLARE_RULE(binary_query_operation,          "binary query expression",         ast::binary_query_operation)
    DECLARE_RULE(binary_query_operator,           "binary query operator",           ast::binary_query_operator)
    DECLARE_RULE(break_statement,                 "break statement",                 ast::break_statement)
    DECLARE_RULE(next_statement,                  "next statement",                  ast::next_statement)
    DECLARE_RULE(return_statement,                "return statement",                ast::return_statement)

    // Syntax tree rules
    DECLARE_RULE(syntax_tree,                     "syntax tree",                     ast::syntax_tree)
    DECLARE_RULE(epp_syntax_tree,                 "syntax tree",                     ast::syntax_tree)

    // Basic expressions
    DEFINE_RULE(
        basic_expression,
        undef                         |
        defaulted                     |
        boolean                       |
        number                        |
        string                        |
        regex                         |
        variable                      |
        function_call_expression      |  // Note: parsing of function call must come before name as it starts with a name
        new_expression                |  // Note: parsing of new expression must come before type as it starts with a type
        name                          |
        bare_word                     |
        type                          |
        interpolated_string           |
        array                         |
        hash                          |
        case_expression               |
        if_expression                 |
        unless_expression             |
        epp_render_block              |  // Note: parsing of EPP render block must come before EPP render expression
        epp_render_expression         |
        epp_render_string             |
        unary_expression              |
        nested_expression
    )
    DEFINE_RULE(
        undef,
        begin(lexer::token_id::keyword_undef, false) > end() > tree
    )
    DEFINE_RULE(
        defaulted,
        begin(lexer::token_id::keyword_default, false) > end() > tree
    )
    DEFINE_RULE(
        boolean,
        (begin(lexer::token_id::keyword_true, false) > boost::spirit::x3::attr(true) > end() > tree) |
        (begin(lexer::token_id::keyword_false, false) > boost::spirit::x3::attr(false) > end() > tree)
    )
    DEFINE_RULE(
        number,
        number_token
    )
    DEFINE_RULE(
        string,
        string_token
    )
    DEFINE_RULE(
        variable,
        begin(lexer::token_id::variable, false) > variable_value > end() > tree
    )
    DEFINE_RULE(
        name,
        (begin(lexer::token_id::name, false) > value > end() > tree) | statement_call_name
    )
    DEFINE_RULE(
        bare_word,
        begin(lexer::token_id::bare_word, false) > value > end() > tree
    )
    DEFINE_RULE(
        type,
        begin(lexer::token_id::type, false) > value > end() > tree
    )
    DEFINE_RULE(
        interpolated_string,
        begin(lexer::token_id::string_start, false) > string_format > *interpolated_string_part > string_margin > end(lexer::token_id::string_end) > tree
    )
    DEFINE_RULE(
        interpolated_string_part,
        literal_string_text | variable | (raw(lexer::token_id::interpolation_start) > expression > raw(lexer::token_id::interpolation_end))
    )
    DEFINE_RULE(
        literal_string_text,
        string_text
    )
    DEFINE_RULE(
        regex,
        begin(lexer::token_id::regex, false) > regex_value > end() > tree
    )
    DEFINE_RULE(
        array,
        (begin('[') | begin(lexer::token_id::array_start)) > (raw(']', false) | expressions) > end(']') > tree
    )
    DEFINE_RULE(
        hash,
        begin('{') > (raw('}', false) | pairs) > end('}') > tree
    )
    DEFINE_RULE(
        pairs,
        (pair % raw(',')) > -raw(',')
    )
    DEFINE_RULE(
        pair,
        expression > raw(lexer::token_id::fat_arrow) > expression
    )
    DEFINE_RULE(
        case_expression,
        begin(lexer::token_id::keyword_case) > expression > raw('{') > +proposition > end('}') > tree
    )
    DEFINE_RULE(
        proposition,
        expressions > raw(':') > raw('{') > (raw('}', false) | statements) > end('}')
    )
    DEFINE_RULE(
        if_expression,
        begin(lexer::token_id::keyword_if) > expression > raw('{') > (raw('}', false) | statements) > end('}') > *elsif > -else_
    )
    DEFINE_RULE(
        elsif,
        begin(lexer::token_id::keyword_elsif) > expression > raw('{') > (raw('}', false) | statements) > end('}')
    )
    DEFINE_RULE(
        else_,
        begin(lexer::token_id::keyword_else) > raw('{') > (raw('}', false) | statements) > end('}')
    )
    DEFINE_RULE(
        unless_expression,
        begin(lexer::token_id::keyword_unless) > expression > raw('{') > (raw('}', false) | statements) > end('}') > -else_
    )
    DEFINE_RULE(
        function_call_expression,
        function_name >> (raw('(') > (raw(')', false) | expressions) > end(')') > -lambda_expression)
    )
    DEFINE_RULE(
        function_name,
        name |
        (
            (
                begin(lexer::token_id::keyword_type, false)
            ) > value > end() > tree
        )
    )
    DEFINE_RULE(
        lambda_expression,
        begin('|') > (raw('|', false) | parameters) > raw('|') > raw('{') > (raw('}', false) | statements) > end('}') > tree
    )
    DEFINE_RULE(
        parameters,
        (parameter % raw(',')) > -raw(',')
    )
    DEFINE_RULE(
        parameter,
        -type_expression >> -begin('*') >> (variable > -(raw('=') > expression))
    )
    DEFINE_RULE(
        type_expression,
        type > *access_expression
    )
    DEFINE_RULE(
        new_expression,
        type_expression >> (raw('(') > (raw(')', false) | expressions) > end(')') > -lambda_expression)
    )
    DEFINE_RULE(
        epp_render_expression,
        begin(lexer::token_id::epp_render_expression) > expression > (end(lexer::token_id::epp_end) | end(lexer::token_id::epp_end_trim)) > tree
    )
    DEFINE_RULE(
        epp_render_block,
        begin(lexer::token_id::epp_render_expression) >> (raw('{') > expressions > raw('}') > (end(lexer::token_id::epp_end) | end(lexer::token_id::epp_end_trim)) > tree)
    )
    DEFINE_RULE(
        epp_render_string,
        begin(lexer::token_id::epp_render_string, false) > value > end() > tree
    )
    DEFINE_RULE(
        unary_expression,
        begin(false) >> (unary_operator > postfix_expression)
    )
    DEFINE_RULE(
        unary_operator,
        (raw('-') > boost::spirit::x3::attr(ast::unary_operator::negate))     |
        (raw('*') > boost::spirit::x3::attr(ast::unary_operator::splat))      |
        (raw('!') > boost::spirit::x3::attr(ast::unary_operator::logical_not))
    )
    DEFINE_RULE(
        nested_expression,
        begin('(') > expression > end(')') > tree
    )

    // Postfix expressions
    DEFINE_RULE(
        postfix_expression,
        basic_expression > *postfix_operation
    )
    DEFINE_RULE(
        postfix_operation,
        selector_expression | access_expression | method_call_expression
    )
    DEFINE_RULE(
        selector_expression,
        begin('?') > raw('{') > pairs > end('}') > tree
    )
    DEFINE_RULE(
        access_expression,
        begin('[') > expressions > end(']') > tree
    )
    DEFINE_RULE(
        method_call_expression,
        begin('.') > function_name > -(raw('(') > (raw(')', false) | expressions) > end(')')) > -lambda_expression
    )

    // General expressions
    DEFINE_RULE(
        expressions,
        (expression % raw(',')) > -raw(',')
    )
    DEFINE_RULE(
        expression,
        postfix_expression > *binary_operation
    )
    DEFINE_RULE(
        binary_operation,
        begin(false) >> (binary_operator > postfix_expression)
    )
    DEFINE_RULE(
        binary_operator,
        (raw(lexer::token_id::keyword_in)     > boost::spirit::x3::attr(ast::binary_operator::in))                 |
        (raw(lexer::token_id::match)          > boost::spirit::x3::attr(ast::binary_operator::match))              |
        (raw(lexer::token_id::not_match)      > boost::spirit::x3::attr(ast::binary_operator::not_match))          |
        (raw('*')                             > boost::spirit::x3::attr(ast::binary_operator::multiply))           |
        (raw('/')                             > boost::spirit::x3::attr(ast::binary_operator::divide))             |
        (raw('%')                             > boost::spirit::x3::attr(ast::binary_operator::modulo))             |
        (raw('+')                             > boost::spirit::x3::attr(ast::binary_operator::plus))               |
        (raw('-')                             > boost::spirit::x3::attr(ast::binary_operator::minus))              |
        (raw(lexer::token_id::left_shift)     > boost::spirit::x3::attr(ast::binary_operator::left_shift))         |
        (raw(lexer::token_id::right_shift)    > boost::spirit::x3::attr(ast::binary_operator::right_shift))        |
        (raw(lexer::token_id::equals)         > boost::spirit::x3::attr(ast::binary_operator::equals))             |
        (raw(lexer::token_id::not_equals)     > boost::spirit::x3::attr(ast::binary_operator::not_equals))         |
        (raw('>')                             > boost::spirit::x3::attr(ast::binary_operator::greater_than))       |
        (raw(lexer::token_id::greater_equals) > boost::spirit::x3::attr(ast::binary_operator::greater_equals))     |
        (raw('<')                             > boost::spirit::x3::attr(ast::binary_operator::less_than))          |
        (raw(lexer::token_id::less_equals)    > boost::spirit::x3::attr(ast::binary_operator::less_equals))        |
        (raw(lexer::token_id::keyword_and)    > boost::spirit::x3::attr(ast::binary_operator::logical_and))        |
        (raw(lexer::token_id::keyword_or)     > boost::spirit::x3::attr(ast::binary_operator::logical_or))         |
        (raw('=')                             > boost::spirit::x3::attr(ast::binary_operator::assignment))
    )

    // Statements
    DEFINE_RULE(
        statements,
        (statement % -raw(';')) > -raw(';')
    )
    DEFINE_RULE(
        statement,
        class_statement         |
        defined_type_statement  |
        node_statement          |
        function_statement      |
        produces_statement      |
        consumes_statement      |
        application_statement   |
        site_statement          |
        type_alias_statement    |
        function_call_statement |
        break_statement         |
        next_statement          |
        return_statement        |
        relationship_statement    // Note: must come last so that produces/consume statements have precedence
    )
    DEFINE_RULE(
        relationship_statement,
        relationship_expression > *relationship_operation
    )
    DEFINE_RULE(
        relationship_expression,
        resource_declaration_expression |
        resource_override_expression    |
        resource_defaults_expression    |
        collector_expression            |
        expression
    )
    DEFINE_RULE(
        relationship_operation,
        begin(false) >> (relationship_operator > relationship_expression)
    )
    DEFINE_RULE(
        relationship_operator,
        (raw(lexer::token_id::in_edge)      > boost::spirit::x3::attr(ast::relationship_operator::in_edge))            |
        (raw(lexer::token_id::in_edge_sub)  > boost::spirit::x3::attr(ast::relationship_operator::in_edge_subscribe))  |
        (raw(lexer::token_id::out_edge)     > boost::spirit::x3::attr(ast::relationship_operator::out_edge))           |
        (raw(lexer::token_id::out_edge_sub) > boost::spirit::x3::attr(ast::relationship_operator::out_edge_subscribe))
    )
    DEFINE_RULE(
        resource_declaration_expression,
        (begin(lexer::token_id::atat) > boost::spirit::x3::attr(ast::resource_status::exported) > resource_type > raw('{') > resource_bodies > end('}') > tree) |
        (begin('@') > boost::spirit::x3::attr(ast::resource_status::virtualized) > resource_type > raw('{') > resource_bodies > end('}') > tree)                |
        (begin(false) >> boost::spirit::x3::attr(ast::resource_status::realized) >> resource_type >> raw('{') >> (resource_bodies > end('}') > tree))
    )
    DEFINE_RULE(
        resource_type,
        ((name | class_name) > boost::spirit::x3::attr(std::vector<ast::postfix_operation>())) |
        (type >> +access_expression)
    )
    DEFINE_RULE(
        class_name,
        begin(lexer::token_id::keyword_class, false) > value > end() > tree
    )
    DEFINE_RULE(
        resource_bodies,
        (resource_body % raw(';')) > -raw(';')
    )
    DEFINE_RULE(
        resource_body,
        (expression >> !raw(lexer::token_id::fat_arrow)) > raw(':') > (attributes | boost::spirit::x3::eps)
    )
    DEFINE_RULE(
        attributes,
        (attribute % raw(',')) > -raw(',')
    )
    DEFINE_RULE(
        attribute,
        attribute_name > begin(false) > raw(lexer::token_id::fat_arrow) > boost::spirit::x3::attr(ast::attribute_operator::assignment) > expression
    )
    DEFINE_RULE(
        attribute_name,
        name                |
        statement_call_name |
        keyword_name        |
        (begin('*', false) > value > end() > tree)
    )
    DEFINE_RULE(
        keyword_name,
        (
            // NOTE: keywords 'true' and 'false' are not valid names
            begin(lexer::token_id::keyword_and, false)         |
            begin(lexer::token_id::keyword_case, false)        |
            begin(lexer::token_id::keyword_class, false)       |
            begin(lexer::token_id::keyword_default, false)     |
            begin(lexer::token_id::keyword_define, false)      |
            begin(lexer::token_id::keyword_else, false)        |
            begin(lexer::token_id::keyword_elsif, false)       |
            begin(lexer::token_id::keyword_if, false)          |
            begin(lexer::token_id::keyword_in, false)          |
            begin(lexer::token_id::keyword_inherits, false)    |
            begin(lexer::token_id::keyword_node, false)        |
            begin(lexer::token_id::keyword_or, false)          |
            begin(lexer::token_id::keyword_undef, false)       |
            begin(lexer::token_id::keyword_unless, false)      |
            begin(lexer::token_id::keyword_type, false)        |
            begin(lexer::token_id::keyword_attr, false)        |
            begin(lexer::token_id::keyword_function, false)    |
            begin(lexer::token_id::keyword_private, false)     |
            begin(lexer::token_id::keyword_produces, false)    |
            begin(lexer::token_id::keyword_consumes, false)    |
            begin(lexer::token_id::keyword_application, false) |
            begin(lexer::token_id::keyword_site, false)        |
            begin(lexer::token_id::keyword_break, false)       |
            begin(lexer::token_id::keyword_next, false)        |
            begin(lexer::token_id::keyword_return, false)
        ) > value > end() > tree
    )
    // Ensure all keywords (except true/false) are present in the list above
    static_assert((static_cast<size_t>(lexer::token_id::last_keyword) - static_cast<size_t>(lexer::token_id::first_keyword)) == (27 + 1), "a keyword is missing from the keyword_name rule.");
    DEFINE_RULE(
        resource_override_expression,
        begin(false) >> resource_override_reference >> (raw('{') > (raw('}', false) | ((attribute_override % raw(',') > -raw(',')))) > end('}') > tree)
    )
    DEFINE_RULE(
        resource_override_reference,
        resource_reference |
        collector_expression
    )
    DEFINE_RULE(
        resource_reference,
        (type >> +access_expression) |
        (variable > *access_expression)
    )
    DEFINE_RULE(
        attribute_override,
        attribute_name > begin(false) > (
            (raw(lexer::token_id::fat_arrow)  > boost::spirit::x3::attr(ast::attribute_operator::assignment)) |
            (raw(lexer::token_id::plus_arrow) > boost::spirit::x3::attr(ast::attribute_operator::append))
        ) > expression
    )
    DEFINE_RULE(
        resource_defaults_expression,
        begin(false) >> type >> (raw('{') > (raw('}', false) | attributes) > end('}') > tree)
    )
    DEFINE_RULE(
        collector_expression,
        (type >> (raw(lexer::token_id::left_double_collect) > boost::spirit::x3::attr(true) > -query_expression > end(lexer::token_id::right_double_collect))) |
        (type >> (raw(lexer::token_id::left_collect) > boost::spirit::x3::attr(false) > -query_expression > end(lexer::token_id::right_collect)))
    )
    DEFINE_RULE(
        query_expression,
        basic_query_expression > *binary_query_operation
    )
    DEFINE_RULE(
        basic_query_expression,
        nested_query_expression | attribute_query
    )
    DEFINE_RULE(
        nested_query_expression,
        begin('(') > query_expression > end(')') > tree
    )
    DEFINE_RULE(
        attribute_query,
        name > begin(false) > query_operator > attribute_query_value
    )
    DEFINE_RULE(
        query_operator,
        (raw(lexer::token_id::equals)     > boost::spirit::x3::attr(ast::query_operator::equals)) |
        (raw(lexer::token_id::not_equals) > boost::spirit::x3::attr(ast::query_operator::not_equals))
    )
    DEFINE_RULE(
        attribute_query_value,
        undef               |
        defaulted           |
        boolean             |
        number              |
        string              |
        interpolated_string |
        regex               |
        variable            |
        name                |
        bare_word           |
        type                |
        array               |
        hash
    )
    DEFINE_RULE(
        binary_query_operation,
        begin(false) >> (binary_query_operator > basic_query_expression)
    )
    DEFINE_RULE(
        binary_query_operator,
        (raw(lexer::token_id::keyword_and) > boost::spirit::x3::attr(ast::binary_query_operator::logical_and)) |
        (raw(lexer::token_id::keyword_or)  > boost::spirit::x3::attr(ast::binary_query_operator::logical_or))
    )
    DEFINE_RULE(
        class_statement,
        (begin(lexer::token_id::keyword_class) >> !raw('{')) >
        name >
        -(raw('(') > (raw(')', false) | parameters) > raw(')')) >
        -(raw(lexer::token_id::keyword_inherits) > name) >
        raw('{') > (raw('}', false) | statements) > end('}') > tree
    )
    DEFINE_RULE(
        defined_type_statement,
        begin(lexer::token_id::keyword_define) >
        name >
        -(raw('(') > (raw(')', false) | parameters) > raw(')')) >
        raw('{') > (raw('}', false) | statements) > end('}') > tree
    )
    DEFINE_RULE(
        node_statement,
        begin(lexer::token_id::keyword_node) > hostnames > raw('{') > (raw('}', false) | statements) > end('}') > tree
    )
    DEFINE_RULE(
        hostnames,
        (hostname % ',') > -raw(',')
    )
    DEFINE_RULE(
        hostname,
        string              |
        defaulted           |
        regex               |
        ((name | bare_word | number) % raw('.'))
    )
    DEFINE_RULE(
        function_statement,
        boost::spirit::x3::matches[raw(lexer::token_id::keyword_private, false)] >>
        (((begin(lexer::token_id::keyword_private) >> raw(lexer::token_id::keyword_function)) | begin(lexer::token_id::keyword_function)) >
        name >
        -(raw('(') > (raw(')', false) | parameters) > raw(')')) >
        raw('{') > (raw('}', false) | statements) > end('}') > tree)
    )
    DEFINE_RULE(
        produces_statement,
        type >> (raw(lexer::token_id::keyword_produces) > type > raw('{') > (raw('}', false) | attributes) > end('}'))
    )
    DEFINE_RULE(
        consumes_statement,
        type >> (raw(lexer::token_id::keyword_consumes) > type > raw('{') > (raw('}', false) | attributes) > end('}'))
    )
    DEFINE_RULE(
        application_statement,
        begin(lexer::token_id::keyword_application) >
        name >
        -(raw('(') > (raw(')', false) | parameters) > raw(')')) >
        raw('{') > (raw('}', false) | statements) > end('}') > tree
    )
    DEFINE_RULE(
        site_statement,
        begin(lexer::token_id::keyword_site) > raw('{') > (raw('}', false) | statements) > end('}') > tree
    )
    DEFINE_RULE(
        type_alias_statement,
        (begin(lexer::token_id::keyword_type) >> type) > raw('=') > type_expression
    )
    DEFINE_RULE(
        function_call_statement,
        statement_call_name >> !raw('(') >> (expressions > -lambda_expression)
    )
    DEFINE_RULE(
        statement_call_name,
        begin(lexer::token_id::statement_call, false) > value > end() > tree
    )
    DEFINE_RULE(
        break_statement,
        ((begin(lexer::token_id::keyword_break) >> raw('(')) > end(')') > tree) |
        (begin(lexer::token_id::keyword_break, false) > end() > tree)
    )
    DEFINE_RULE(
        next_statement,
        ((begin(lexer::token_id::keyword_next) >> raw('(') >> end(')')) > tree > boost::spirit::x3::attr(boost::none)) |
        (begin(lexer::token_id::keyword_next, false) > end() > tree > -expression)
    )
    DEFINE_RULE(
        return_statement,
        ((begin(lexer::token_id::keyword_return) >> raw('(') >> end(')')) > tree > boost::spirit::x3::attr(boost::none)) |
        (begin(lexer::token_id::keyword_return, false) > end() > tree > -expression)
    )

    // Syntax tree rules
    DEFINE_RULE(
        syntax_tree,
        boost::spirit::x3::attr(boost::none) > (statements | boost::spirit::x3::eps)
    )
    DEFINE_RULE(
        epp_syntax_tree,
        -(raw('|') > (raw('|', false) | parameters) > raw('|')) > (statements | boost::spirit::x3::eps)
    )

    // These macros associate the above rules with their definitions
    BOOST_SPIRIT_DEFINE(
        basic_expression,
        undef,
        defaulted,
        boolean,
        number,
        string,
        regex,
        variable,
        name,
        bare_word,
        type,
        interpolated_string,
        interpolated_string_part,
        literal_string_text,
        array,
        hash,
        pairs,
        pair,
        case_expression,
        proposition,
        if_expression,
        elsif,
        else_,
        unless_expression,
        function_call_expression,
        function_name,
        lambda_expression,
        parameters,
        parameter,
        type_expression,
        new_expression,
        epp_render_expression,
        epp_render_block,
        epp_render_string,
        unary_expression,
        unary_operator,
        nested_expression
    );

    BOOST_SPIRIT_DEFINE(
        postfix_expression,
        postfix_operation,
        selector_expression,
        access_expression,
        method_call_expression
    );

    BOOST_SPIRIT_DEFINE(
        expressions,
        expression,
        binary_operation,
        binary_operator
    );

    BOOST_SPIRIT_DEFINE(
        statements,
        statement,
        class_statement,
        defined_type_statement,
        node_statement,
        hostnames,
        hostname,
        function_statement,
        produces_statement,
        consumes_statement,
        application_statement,
        site_statement,
        type_alias_statement,
        function_call_statement,
        statement_call_name,
        relationship_statement,
        relationship_expression,
        relationship_operation,
        relationship_operator,
        resource_declaration_expression,
        resource_type,
        class_name,
        resource_bodies,
        resource_body,
        attributes,
        attribute,
        attribute_name,
        keyword_name,
        resource_override_expression,
        resource_override_reference,
        resource_reference,
        attribute_override,
        resource_defaults_expression,
        collector_expression,
        query_expression,
        basic_query_expression,
        nested_query_expression,
        attribute_query,
        query_operator,
        attribute_query_value,
        binary_query_operation,
        binary_query_operator,
        break_statement,
        next_statement,
        return_statement
    );

    BOOST_SPIRIT_DEFINE(
        syntax_tree,
        epp_syntax_tree
    );

    /// @endcond

}}}  // namespace puppet::compiler::parser
