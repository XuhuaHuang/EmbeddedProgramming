/**
 * @file make_arithmetic.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-02-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <boost/proto/proto.hpp>
#include <iostream>

namespace proto_example {

using namespace boost::proto;

// Define the expression grammar
struct expression_grammar : or_<
                              terminal<int>::type,
                              plus<expression_grammar, expression_grammar>,
                              minus<expression_grammar, expression_grammar>,
                              multiplies<expression_grammar, expression_grammar>,
                              divides<expression_grammar, expression_grammar>> {};

// Define the expression domain, which is a domain of expression tree nodes
struct expression_domain : domain<generator<expression_grammar>, expression_grammar> {};

// Declare an expression template
using expression_template = boost::proto::expression<expression_domain>;

// Define a few utility functions
expression_template make_plus(const expression_template& left, const expression_template& right) {
  return left + right;
}

expression_template make_minus(const expression_template& left, const expression_template& right) {
  return left - right;
}

expression_template make_multiplies(const expression_template& left, const expression_template& right) {
  return left * right;
}

expression_template make_divides(const expression_template& left, const expression_template& right) {
  return left / right;
}

} // namespace proto_example

int main() {
  // Create some expressions
  proto_example::expression_template x = 42;
  proto_example::expression_template y = 7;
  proto_example::expression_template z = proto_example::make_plus(x, y);

  // Print the expression tree
  std::cout << z << std::endl;

  return 0;
}
